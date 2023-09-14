/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/14 12:23:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	prompt(t_sh_context *shx, char **env)
{
	// t_str	str_prompt;
	t_uint	status;

	(void)env;
	status = CONTINUE_PROC;
	while (status != EXIT_SHELL)
	{
		// Gérez les signaux (ctrl-C, ctrl-D, ctrl-\)

		// Gérez les variables d'environnement ($)
		// str_prompt = ft_strdup(shx, (t_str)lst_get(&shx->envp, lst_get_index(&shx->envp, "PWD=", 4)));
		// if (!str_prompt)
		// 	return (handle_error(MALLOC_FAIL, NULL));
		// str_prompt += 4;
		// str_prompt = ft_strfjoin(shx, str_prompt, "$ ");
		// if (!str_prompt)
		// 	return (handle_error(MALLOC_FAIL, NULL));
		while (!shx->line || !shx->line[0])
		{
			shx->line = readline(/*str_prompt*/"==========minishell> ");
			if (!shx->line)
				return (EXIT_SHELL);
		}
		// shx->gc->free(shx, str_prompt);
		printf("[%s]\n", shx->line);
		status = check_syntax(shx->line);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (shx->line[0])
			add_history(shx->line);
		if (shx->line[0])
		{
			status = split_line(shx, &shx->line_split, shx->line);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		status = pars_line(shx, &shx->blocks, shx->line_split);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		log_struct(shx);
		status = processing(&shx->blocks);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		clean_blocks(shx, &shx->blocks);
		free(shx->line);
		shx->line = NULL;
	}
	return (CONTINUE_PROC);
}
