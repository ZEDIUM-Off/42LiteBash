/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/13 14:43:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(t_sh_context *shx, char **env)
{
	t_str	str_prompt;
	int		status;

	(void)env;
	status = 0;
	while (42)
	{
		// Gérez les signaux (ctrl-C, ctrl-D, ctrl-\)

		// Parsez la commande et gérez les guillemets, les caractères spéciaux, etc.

		// Gérez les builtins (echo, cd, pwd, export, unset, env, exit)

		// Gérez les redirections (<, >, <<, >>)

		// Gérez les pipes (|)

		// Gérez les variables d'environnement ($)

		// Gérez les wildcards (*)

		// Exécutez la commande avec fork et exec
		// char *test = shx->gc->malloc(shx, 10, true);
		// shx->gc->free(shx, test);
		str_prompt = ft_strdup(shx, (t_str)lst_get(&shx->envp, lst_get_index(&shx->envp, "PWD=", 4)));
		str_prompt += 4;
		str_prompt = ft_strfjoin(shx, str_prompt, "$ ");
		if (!str_prompt)
			return ;
		while (!shx->line || !shx->line[0])
			shx->line = readline(str_prompt);
		add_history(shx->line);
		shx->gc->free(shx, str_prompt);
		printf("[%s]\n", shx->line);
		shx->status = check_syntax(shx->line);
		if (shx->status == SYNTAX_ERROR)
			printf("Syntax error\n");
		if (shx->line[0])
			add_history(shx->line);
		if (shx->line[0] && shx->status == SYNTAX_OK)
			split_line(shx, &shx->line_split, shx->line);
		status = pars_line(shx, &shx->blocks, shx->line_split);
		printf("status = %i\n", status);
		if (status != 0)
			return ;
		log_struct(shx);
		processing(&shx->blocks);
		// printf("processing done\n");
		clean_blocks(shx, &shx->blocks);
		free(shx->line);
		shx->line = NULL;
	}
	return ;
}
