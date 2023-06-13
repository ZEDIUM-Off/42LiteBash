/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/13 15:55:12 by bfaure           ###   ########lyon.fr   */
=======
/*   Updated: 2023/06/13 11:46:36 by  mchenava        ###   ########.fr       */
>>>>>>> 4956b9e1e5b508b64b11398eb9b8c3b09a889959
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
		if (g_shx->line[0])
			add_history(g_shx->line);
		//ft_read(line_read);
		if (g_shx->line[0] && g_shx->status == SYNTAX_OK)
			split_line();
		log_action();
		free(g_shx->line);
	}
	log_action();
	return ;
}
