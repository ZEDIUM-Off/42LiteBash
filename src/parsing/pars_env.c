/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/13 23:02:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	add_env_to_lst(t_sh_context *shx, t_list	*lst_env, char **envp)
{
	t_uint	status;
	int		i;

	i = 0;
	lst_env = NULL;
	while (envp[i])
	{
		status = lst_add_back(shx, &lst_env, envp[i], i);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		i++;
	}
	return (CONTINUE_PROC);
}

void	swap_nodes(t_list *current_node, t_list *next_node)
{
	char	*data;

	data = NULL;
	data = current_node->data;
	current_node->data = next_node->data;
	next_node->data = data;
}

void	sort_env_export(t_sh_context *shx)
{
	t_uint	to_sort;
	t_list	*tmp;
	t_list	*end;

	to_sort = 1;
	end = NULL;
	while (to_sort)
	{
		to_sort = 0;
		tmp = shx->envx;
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
