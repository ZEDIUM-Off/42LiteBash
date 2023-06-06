/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 17:38:26 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(void)
{
	t_str	line_read;
	t_uint	i;

	i = 0;
	trace("prompt", "display prompt", PARSE);
	while (i++ < 10)
	{
		line_read = readline("Minish : ");
		printf("%s\n", line_read);
		ft_read(line_read);
		free(line_read);
	}
	log_action();
	return ;
}
