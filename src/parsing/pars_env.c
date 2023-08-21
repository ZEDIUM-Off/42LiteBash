/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/21 16:50:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*add_env_to_lst(char **envp)
{
	t_list	*lst_env;
	int		i;

	i = -1;
	trace("add_env_to_lst", "every things is in the name", PARSE);
	lst_env = NULL;
	while (envp[++i])
		lst_add_back(&lst_env, envp[i], i);
	log_action();
	return (lst_env);
}

void	swap_nodes(t_list *current_node, t_list *next_node)
{
	// t_uint		index;
	char	*data;

	data = NULL;
	// index = current_node->index;
	// current_node->index = next_node->index;
	// next_node->index = index;
	data = current_node->data;
	current_node->data = next_node->data;
	next_node->data = data;
}

void	sort_env_export(void)
{
	t_uint	to_sort;
	t_list	*tmp;
	t_list	*end;

	to_sort = 1;
	end = NULL;
	while (to_sort)
	{
		to_sort = 0;
		tmp = g_shx->envx;
		while (tmp->next != end)
		{
			if (ft_strncmp(tmp->data, tmp->next->data,
					ft_strlen(tmp->data)) > 0)
			{
				swap_nodes(tmp, tmp->next);
				to_sort = 1;
			}
			tmp = tmp->next;
		}
		end = tmp;
	}
}
