/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/14 19:44:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(char **env)
{
	t_uint	i;
	t_str	str_prompt;

	i = 0;
	(void)env;
	trace("prompt", "display prompt", PARSE);
	using_history();
	read_history(".history");
	stifle_history(1000);
	while (i++ < 10)
	{
		// Gérez les signaux (ctrl-C, ctrl-D, ctrl-\)

		// Parsez la commande et gérez les guillemets, les caractères spéciaux, etc.

		// Gérez les builtins (echo, cd, pwd, export, unset, env, exit)

		// Gérez les redirections (<, >, <<, >>)

		// Gérez les pipes (|)

		// Gérez les variables d'environnement ($)

		// Gérez les wildcards (*)

		// Exécutez la commande avec fork et exec

		str_prompt = lst_get(&g_shx->envp, 32);
		str_prompt += 4;
		str_prompt = ft_strjoin(str_prompt, "$ ");
		g_shx->line = readline(str_prompt);
		free(str_prompt);
		printf("%s\n", g_shx->line);
		g_shx->status = check_syntax(g_shx->line);
		if (g_shx->status == SYNTAX_ERROR)
			printf("Syntax error\n");
		// if (!ft_strncmp(g_shx->line, "exit", 5))
		// 	exit_shell(420, "You say it, you assume it\n");
		// if (!ft_strncmp(g_shx->line, "env", 3))
		// 	lst_print(&g_shx->envp, "lst envp %s\n");
		// if (!ft_strncmp(g_shx->line, "pwd", 3))
		// 	pwd_builtins();
		if (g_shx->line[0])
			add_history(g_shx->line);
		if (g_shx->line[0] && g_shx->status == SYNTAX_OK)
			split_line(&g_shx->line_split, g_shx->line);
		pars_line(&g_shx->blocks, g_shx->line_split);
		log_struct();
		if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == ECHO_BI)
			exec_echo(&g_shx->blocks->ppl->cmd);
		if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == CD_BI)
			cd_builtins(g_shx->line_split[1]);
		if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == PWD_BI)
			pwd_builtins();
		// if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == EXPORT_BI)
		// if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == UNSET_BI)
		if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == ENV_BI)
			lst_print(&g_shx->envp, "lst envp %u %s\n");
		if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == EXIT_BI)
			exit_shell(420, "You say it, you assume it\n");
		log_action();
		clean_blocks(&g_shx->blocks);
		g_shx->gc->free(g_shx->line);
	}
	log_action();
	return ;
}
