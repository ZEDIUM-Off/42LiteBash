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
	t_uint	index;
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

t_list	*lst_create(void *data);
void	lst_add_front(t_list **lst, void *data);
void	lst_add_back(t_list **lst, void *data);
void	lst_print(t_list **lst, t_str text);
void	lst_clear(t_list **lst);
void	lst_insert(t_list **lst, void *data, t_uint index);
void	lst_remove(t_list **lst, t_uint index);
void	lst_remove_first(t_list **lst);
void	lst_remove_last(t_list **lst);
t_list	*lst_get(t_list **lst, t_uint index);
void	lst_set(t_list **lst, t_uint index, void *data);
t_list	*lst_get_first(t_list **lst);
t_list	*lst_get_last(t_list **lst);
t_uint	lst_size(t_list **lst);

t_dlist	*dlst_create(void *data);
void	dlst_add_front(t_dlist **dlst, void *data);
void	dlst_add_back(t_dlist **dlst, void *data);
void	dlst_print(t_dlist **dlst, t_str text);
void	dlst_clear(t_dlist **dlst);
void	dlst_insert(t_dlist **dlst, void *data, t_uint index);
void	dlst_remove(t_dlist **dlst, t_uint index);
void	dlst_remove_first(t_dlist **dlst);
void	dlst_remove_last(t_dlist **dlst);
t_dlist	*dlst_get(t_dlist **dlst, t_uint index);
void	dlst_set(t_dlist **dlst, t_uint index, void *data);
t_dlist	*dlst_get_first(t_dlist **dlst);
t_dlist	*dlst_get_last(t_dlist **dlst);
t_uint	dlst_size(t_dlist **dlst);

#endif