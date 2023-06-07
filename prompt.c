/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/07 18:09:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(void)
{
	t_str	line_read;
	t_uint	i;

	i = 0;
	trace("prompt", "display prompt", PARSE);
	using_history();
	read_history(".history");
	stifle_history(1000);
	while (i++ < 10)
	{
		line_read = readline("Minish : ");
		printf("%s\n", line_read);
		if (!ft_strncmp(line_read, "exit", 5))
			exit_shell(420, "You say it, you assume it\n");
		if (line_read[0])
			add_history(line_read);
		ft_read(line_read);
		free(line_read);
	}
	log_action();
	return ;
}
