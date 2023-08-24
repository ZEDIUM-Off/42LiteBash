/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_base_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/23 16:01:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*lst_create(void *data, t_uint index)
{
	t_list	*new;

	new = g_shx->gc->malloc(sizeof(t_list), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	lst_print(t_list **lst, t_str text)

{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf(text, tmp->index, tmp->data);
		tmp = tmp->next;
	}
}

void	lst_clear(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

t_uint	lst_size(t_list **lst)
{
	t_list	*tmp;
	t_uint	i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	lst_remplace(t_list **lst, t_uint index, t_str data)
{
	t_list	*tmp;
	t_uint	i;

	trace("lst_remplace", "remplace data lst", PARSE);
	if (!lst)
		return ;
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		g_shx->gc->free(tmp->data);
		tmp->data = ft_strdup(data);
	}
	printf("lst remplace index = %u\n", index);
	printf("lst remplace data = %s\n", data);
	if (tmp)
		printf("lst remplace tmp->data = %s\n", (char *)tmp->data);
	log_action();
}
