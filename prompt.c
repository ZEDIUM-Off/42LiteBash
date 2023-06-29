/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/29 14:00:16 by bfaure           ###   ########lyon.fr   */
=======
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/29 13:31:25 by  mchenava        ###   ########.fr       */
>>>>>>> 828a229af1d21f28adf8700969132c7f56934877
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(char **env)
{
	t_uint	i;

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
    
		g_shx->line = readline("Minish : ");
		printf("%s\n", g_shx->line);
		g_shx->status = check_syntax(g_shx->line);
		if (g_shx->status == SYNTAX_ERROR)
			printf("Syntax error\n");
		if (!ft_strncmp(g_shx->line, "exit", 5))
			exit_shell(420, "You say it, you assume it\n");
		if (!ft_strncmp(g_shx->line, "env", 3))
			lst_print(&g_shx->envp, "lst envp %s\n");
		if (g_shx->line[0])
			add_history(g_shx->line);
		if (g_shx->line[0] && g_shx->status == SYNTAX_OK)
			split_line(&g_shx->line_split, g_shx->line);
		pars_line(&g_shx->blocks, g_shx->line_split);
		log_struct();
		exec_echo(&g_shx->blocks->ppl->cmd);
		log_action();
		clean_blocks(&g_shx->blocks);
		g_shx->gc->free(g_shx->line);
	}
	log_action();
	return ;
}
