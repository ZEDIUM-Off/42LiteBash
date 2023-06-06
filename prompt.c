/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:40:16 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 13:51:25 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	prompt(void)
{
	t_str	line_read;

	while (1)
	{
		line_read = readline("Minish : ");
		printf("%s\n", line_read);
		
		free(line_read);
	}
	return ;
}
