/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/27 12:07:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	get_prompt(t_sh_context	*shx)
{
	t_str	str_prompt;

	ft_read_history();
	str_prompt = ft_strdup(shx, (t_str)lst_get(&shx->envp,
				lst_get_index(&shx->envp, "PWD=")));
	if (!str_prompt)
		return (handle_error(MALLOC_FAIL, NULL));
	str_prompt += 4;
	str_prompt = ft_strjoin(shx, str_prompt, "$> ");
	if (!str_prompt)
		return (handle_error(MALLOC_FAIL, NULL));
	while (!shx->line || !shx->line[0])
	{
		shx->line = readline(str_prompt);
		if (!shx->line)
			return (EXIT_SHELL);
	}
	shx->gc->free(shx, str_prompt);
	printf("[%s]\n", shx->line);
	if (shx->line[0])
		ft_write_history(shx->line);
	return (CONTINUE_PROC);
}

t_uint	format_prompt(t_sh_context *shx)
{
	t_uint	status;

	if (shx->line[0])
	{
		status = split_line(shx, &shx->line_split, shx->line);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (shx->line_split && shx->line_split[0])
		{
			free(shx->line);
			shx->line = NULL;
		}
	}
	t_uint i =0;
	while (shx->line_split[i])
	{
		printf("[%s]", shx->line_split[i]);
		i++;
	}
	printf ("\n");
	return (check_syntax(shx->line_split));
}

t_uint	use_prompt(t_sh_context *shx)
{
	t_uint	status;

	status = pars_line(shx, &shx->blocks, shx->line_split);
	if (status != CONTINUE_PROC)
		return (clean_blocks(shx, &shx->blocks), handle_error(status, NULL));
	log_struct(shx);
	status = processing(&shx->blocks);
	if (status != CONTINUE_PROC)
		return (clean_blocks(shx, &shx->blocks), handle_error(status, NULL));
	clean_blocks(shx, &shx->blocks);
	return (CONTINUE_PROC);
}

t_uint	prompt(t_sh_context *shx)
{
	t_uint	status;

	status = CONTINUE_PROC;
	while (status != EXIT_SHELL)
	{
		signal(SIGINT, handle_sigint);
		status = get_prompt(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = format_prompt(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (shx->line_split && shx->line_split[0])
			status = use_prompt(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (status);
}
