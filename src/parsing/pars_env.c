/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/24 10:46:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	add_env_to_lst(t_sh_context *shx, char **envp)
{
	t_uint	status;
	int		i;

	i = 0;
	while (envp[i])
	{
		status = lst_add_back(shx, &shx->env, envp[i]);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		i++;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_to_tab(t_sh_context *shx)
{
	t_uint	i;
	t_list	*tmp;

	i = 0;
	tmp = shx->env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (shx->envp)
		gc_free(shx, shx->envp);
	shx->envp = gc_malloc(shx, sizeof(char *) * (i + 1), true);
	if (!shx->envp)
		return (handle_error(MALLOC_FAIL, NULL));
	i = 0;
	tmp = shx->env;
	while (tmp)
	{
		shx->envp[i++] = ft_strdup(shx, tmp->data);
		if (!shx->envp[i - 1])
			return (handle_error(MALLOC_FAIL, NULL));
		tmp = tmp->next;
	}
	return (shx->envp[i] = NULL, CONTINUE_PROC);
}

void	swap_nodes(t_list *current_node, t_list *next_node)
{
	char	*data;

	data = NULL;
	data = current_node->data;
	current_node->data = next_node->data;
	next_node->data = data;
}

t_list	*sort_str_list(t_list **lst)
{
	t_list	*sorted;
	t_list	*tmp;

	sorted = *lst;
	tmp = sorted;
	while (sorted)
	{
		if (sorted->next
			&& ft_strcmp(sorted->data, sorted->next->data) > 0)
		{
			swap_nodes(sorted, sorted->next);
			sorted = *lst;
		}
		else
			sorted = sorted->next;
	}
	return (tmp);
}
