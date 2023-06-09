/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/09 10:16:20 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	split_line(t_str line_read)
{
	t_uint	i;
	t_str	*str_tab;

	i = 0;
	trace("split_line", "split the line", PARSE);
	str_tab = ft_split_space_tab(line_read);
	if (!str_tab)
		return (printf("MALLOC FAIL IN SPLIT LINE"), -1);
	while (str_tab[i])
	{
		printf("str_tab[%i] = [%s]\n", i, str_tab[i]);
		i++;
	}
	ft_free_tab(str_tab);
	log_action();
	return (0);
}
