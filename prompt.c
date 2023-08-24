/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/24 12:57:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(char **env)
{
	// t_uint	i;
	t_str	str_prompt;
	int		status;

	// i = 0;
	(void)env;
	trace("prompt", "display prompt", PARSE);
	using_history();
	read_history(".history");
	stifle_history(1000);
	status = 0;
	while (1)
	{
		// Gérez les signaux (ctrl-C, ctrl-D, ctrl-\)

		// Parsez la commande et gérez les guillemets, les caractères spéciaux, etc.

		// Gérez les builtins (echo, cd, pwd, export, unset, env, exit)

		// Gérez les redirections (<, >, <<, >>)

		// Gérez les pipes (|)

		// Gérez les variables d'environnement ($)

		// Gérez les wildcards (*)

		// Exécutez la commande avec fork et exec
		str_prompt = lst_get(&g_shx->envp, lst_get_index(&g_shx->envp, "PWD=", 4));
		str_prompt += 4;
		str_prompt = ft_strjoin(str_prompt, "$ ");
		if (!str_prompt)
			return ;
		g_shx->line = readline(str_prompt);
		free(str_prompt);
		printf("%s\n", g_shx->line);
		g_shx->status = check_syntax(g_shx->line);
		if (g_shx->status == SYNTAX_ERROR)
			printf("Syntax error\n");
		if (g_shx->line[0])
			add_history(g_shx->line);
		if (g_shx->line[0] && g_shx->status == SYNTAX_OK)
			split_line(&g_shx->line_split, g_shx->line);
		status = pars_line(&g_shx->blocks, g_shx->line_split);
		printf("status = %i\n", status);
		if (status != 0)
			continue ;
		log_struct();
		processing(&g_shx->blocks);

		// if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == ECHO_BI)
		// 	exec_echo(&g_shx->blocks->ppl->cmd);
		// else if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == CD_BI)
		// 	cd_builtins(g_shx->line_split[1]);
		// else if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == PWD_BI)
		// 	pwd_builtins();
		// else if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == EXPORT_BI)
		// 	export_cmd(&g_shx->blocks->ppl->cmd);
		// if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == UNSET_BI)
		// 	unset_cmd(&g_shx->blocks->ppl->cmd);
		// else if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == ENV_BI)
		// 	lst_print(&g_shx->envp, "lst envp %u %s\n");
		// else if (check_builtins(g_shx->blocks->ppl->cmd->cmd[0]) == EXIT_BI)
		// 	exit_shell(420, "You say it, you assume it\n");
		log_action();
		clean_blocks(&g_shx->blocks);
		g_shx->gc->free(g_shx->line);
	}
	log_action();
	return ;
}
