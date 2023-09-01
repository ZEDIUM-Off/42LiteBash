/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_base_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:23:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_dlist	*dlst_create(t_sh_context *shx, void *data)
{
	t_dlist	*new;

	new = shx->gc->malloc(shx, sizeof(t_dlist), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	dlst_print(t_dlist **dlst, t_str text)
{
	t_dlist	*tmp;

	tmp = *dlst;
	while (tmp)
	{
		printf(text, tmp->data);
		tmp = tmp->next;
	}
}

void	dlst_clear(t_sh_context *shx, t_dlist **dlst)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = *dlst;
	while (tmp)
	{
		tmp2 = tmp->next;
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
		tmp = tmp2;
	}
	*dlst = NULL;
}

t_uint	dlst_size(t_dlist **dlst)
{
	t_dlist	*tmp;
	t_uint	i;

	i = 0;
	tmp = *dlst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
