/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:39:14 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/28 13:39:14 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <minish.h>

struct	s_list
{
	void	*data;
	t_list	*next;
};

struct	s_dlist
{
	t_dlist	*prev;
	t_uint	index;
	void	*data;
	t_dlist	*next;
};

t_list	*lst_create(t_sh_context *shx, void *data);
t_uint	lst_add_front(t_sh_context *shx,
			t_list **lst, void *data, t_uint index);
t_uint	lst_add_back(t_sh_context *shx, t_list **lst, void *data, t_uint index);
t_uint	lst_print(t_list **lst, t_str text);
t_uint	lst_clear(t_sh_context *shx, t_list **lst);
t_uint	lst_insert(t_sh_context *shx, t_list **lst, void *data, t_uint index);
t_uint	lst_remove(t_sh_context *shx, t_list **lst, t_uint index);
t_uint	lst_remove_first(t_sh_context *shx, t_list **lst);
t_uint	lst_remove_last(t_sh_context *shx, t_list **lst);
void	*lst_get(t_list **lst, t_uint index);
t_uint	lst_set(t_list **lst, t_uint index, void *data);
t_uint	index_list_value(t_list **lst);
t_list	*lst_get_first(t_list **lst);
t_list	*lst_get_last(t_list **lst);
t_uint	lst_size(t_list **lst);
t_uint	lst_get_index(t_list **lst, t_str name);
t_uint	lst_remplace(t_sh_context *shx, t_list **lst, t_uint index, t_str data);

t_dlist	*dlst_create(t_sh_context *shx, void *data);
void	dlst_add_front(t_sh_context *shx, t_dlist **dlst, void *data);
void	dlst_add_back(t_sh_context *shx, t_dlist **dlst, void *data);
void	dlst_print(t_dlist **dlst, t_str text);
void	dlst_clear(t_sh_context *shx, t_dlist **dlst);
void	dlst_insert(t_sh_context *shx,
			t_dlist **dlst, void *data, t_uint index);
void	dlst_remove(t_sh_context *shx, t_dlist **dlst, t_uint index);
void	dlst_remove_first(t_sh_context *shx, t_dlist **dlst);
void	dlst_remove_last(t_sh_context *shx, t_dlist **dlst);
t_dlist	*dlst_get(t_dlist **dlst, t_uint index);
void	dlst_set(t_dlist **dlst, t_uint index, void *data);
t_dlist	*dlst_get_first(t_dlist **dlst);
t_dlist	*dlst_get_last(t_dlist **dlst);
t_uint	dlst_size(t_dlist **dlst);
t_uint	lst_append(t_sh_context *shx, t_list **lst, t_uint index, t_str data);

#endif