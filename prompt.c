/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/24 12:56:55 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	get_prompt(t_sh_context	*shx)
{
	t_str	str_prompt;
	t_str	pwd;

	ft_read_history(shx);
	str_prompt = ft_strfjoin(shx, ft_itoa(shx, g_exit_status), " - ");
	pwd = lst_get(&shx->env, lst_get_index(&shx->env, "PWD="));
	if (pwd)
		str_prompt = ft_strfjoin(shx, str_prompt, &pwd[4]);
	str_prompt = ft_strfjoin(shx, str_prompt, "$> ");
	if (!str_prompt)
		return (handle_error(MALLOC_FAIL, NULL));
	while (!shx->line || !shx->line[0])
	{
		shx->line = readline(str_prompt);
		if (!shx->line)
			return (EXIT_SHELL);
	}
	g_exit_status = 0;
	shx->gc->free(shx, str_prompt);
	if (shx->line[0])
		ft_write_history(shx, shx->line);
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
		if ((shx->line_split && shx->line_split[0]) || shx->line)
		{
			free(shx->line);
			shx->line = NULL;
		}
	}
	return (check_syntax(shx->line_split));
}

t_uint	use_prompt(t_sh_context *shx)
{
	t_uint	status;

	status = lst_to_tab(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	shx->lst_paths = get_path(shx, shx->envp);
	status = pars_line(shx, &shx->blocks, shx->line_split);
	if (status != CONTINUE_PROC)
		return (clean_blocks(shx, &shx->blocks), handle_error(status, NULL));
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
		signal(SIGQUIT, SIG_IGN);
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
