/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/27 15:41:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_expand(t_str *splited)
{
	t_uint	i;
	t_uint	j;
	t_list	*tmp;

	i = 0;
	j = 0;
	(void) j;
	tmp = g_shx->envp;
	while (splited[i])
	{
		if (splited[i][0] == '$')
		{
			splited[i]++;
			while (tmp)
			{
				if (ft_strncmp(splited[i], tmp->data, ft_strlen(tmp->data)))
				{
					printf("check_expand 1 -> splited[%i] = %s\n", i, splited[i]);
					printf("check_expand 1 -> tmp->data = %s\n", (char *)tmp->data);
					splited[i]--;
					while (*(char *)tmp->data != '=')
						tmp->data++;
					printf("check_expand 2 -> tmp->data = %s\n", (char *)tmp->data);
					splited[i] = ft_strdup(tmp->data);
					printf("check_expand 2 -> splited[%i] = %s\n", i, splited[i]);
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}
