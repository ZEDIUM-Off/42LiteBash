/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/29 11:04:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_expand(t_str *splited)
{
	t_uint	i;
	t_uint	j;
	t_list	*tmp;

	i = 0;
	while (splited[i])
	{
		if (splited[i][0] == '$')
		{
			tmp = g_shx->envp;
			while (tmp)
			{
				if (!ft_strncmp(
						&splited[i][1], tmp->data, ft_strlen(&splited[i][1])))
				{
					printf("check_expand var found = %s\n", (t_str)tmp->data);
					j = 0;
					while (((t_str)(tmp->data))[j] != '=')
						j++;
					j++;
					splited[i] = ft_strdup(&tmp->data[j]);
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}
