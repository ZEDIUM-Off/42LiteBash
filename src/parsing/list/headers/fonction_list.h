/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chain_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:56:09 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/28 14:56:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTION_LIST_H
# define FONCTION_LIST_H

# include "list.h"
# include <stdlib.h>
# include "../../parsing.h"

void	ft_lstclear(t_list *lst);
void	ft_print_list(t_list *lst);
void	ft_lstdel_link(t_list *lst, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);

size_t	ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);
// t_list	*make_list(t_data *data);
t_list	*ft_lstnew(char *content);

#endif