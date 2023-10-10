/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/05 10:45:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	get_prompt(t_sh_context	*shx)
{
	t_str	str_prompt;

	str_prompt = ft_strdup(shx, (t_str)lst_get(&shx->envp,
				lst_get_index(&shx->envp, "PWD=")));
	if (!str_prompt)
		return (handle_error(MALLOC_FAIL, NULL));
	str_prompt += 4;
	str_prompt = ft_strfjoin(shx, str_prompt, "$ ");
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
		add_history(shx->line);
	return (CONTINUE_PROC);
}

t_uint	format_prompt(t_sh_context *shx)
{
	t_uint	status;
	t_uint	i;

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
		i = 0;
		while (shx->line_split[i])
		{
			printf("[%s]\n", shx->line_split[i]);
			i++;
		}
	}
	status = check_syntax(shx->line_split);
	return (status);
}

t_uint	use_prompt(t_sh_context *shx)
{
	t_uint	status;

	status = pars_line(shx, &shx->blocks, shx->line_split);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	log_struct(shx);
	status = processing(&shx->blocks);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	clean_blocks(shx, &shx->blocks);
	return (CONTINUE_PROC);
}

// Gérez les signaux (ctrl-C, ctrl-D, ctrl-\)
t_uint	prompt(t_sh_context *shx)
{
	t_uint	status;

	status = CONTINUE_PROC;
	while (status != EXIT_SHELL)
	{
		status = get_prompt(shx);
		if (status != CONTINUE_PROC)
			continue ;
		status = format_prompt(shx);
		if (status != CONTINUE_PROC)
			continue ;
		if (status == CONTINUE_PROC && shx->line_split && shx->line_split[0])
			status = use_prompt(shx);
	}
	return (status);
}
