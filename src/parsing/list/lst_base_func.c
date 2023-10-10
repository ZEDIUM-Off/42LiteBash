/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_base_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/29 18:24:25 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*lst_create(t_sh_context *shx, void *data)
{
	t_list	*new;

	new = shx->gc->malloc(shx, sizeof(t_list), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_uint	lst_print(t_list **lst, t_str text)

{
	t_list	*tmp;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	while (tmp)
	{
		printf(text, tmp->data);
		tmp = tmp->next;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_clear(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
		tmp = tmp2;
	}
	*lst = NULL;
	return (CONTINUE_PROC);
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

t_uint	lst_remplace(t_sh_context *shx, t_list **lst, t_uint index, t_str data)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	if (!data)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		shx->gc->free(shx, tmp->data);
		tmp->data = ft_strdup(shx, data);
		if (!tmp->data)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}
