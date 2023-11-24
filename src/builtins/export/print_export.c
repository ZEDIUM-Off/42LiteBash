/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:29:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/24 14:31:40 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	p_env(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	while (tmp)
	{
		if (ft_strcspn(tmp->data, "=") != ft_strlen(tmp->data))
			printf("%s\n", ((char *)tmp->data));
		tmp = tmp->next;
	}
	return (CONTINUE_PROC);
}

static t_uint	p_export(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;
	t_str	str_tmp;
	t_uint	i;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	while (tmp)
	{
		str_tmp = NULL;
		i = 0;
		printf("declare -x ");
		while (i <= ft_strcspn(tmp->data, "="))
			printf("%c", ((char *)tmp->data)[i++]);
		if (ft_strcspn(tmp->data, "=") == ft_strlen(tmp->data))
			i--;
		str_tmp = ft_strdup(shx, &((char *)tmp->data)[i]);
		if ((str_tmp && str_tmp[0] != '\0')
			|| ft_strcspn(tmp->data, "=") != ft_strlen(tmp->data))
			printf("\"%s\"", str_tmp);
		printf("\n");
		tmp = tmp->next;
	}
	return (CONTINUE_PROC);
}

t_uint	print_envs(t_sh_context *shx, t_uint mode,
	t_list **lst)
{
	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	if (mode == ENV_BI)
	{
		if (p_env(lst) != CONTINUE_PROC)
			return (handle_error(NULL_DATA, NULL));
	}
	else if (mode == EXPORT_BI)
	{
		if (p_export(shx, lst) != CONTINUE_PROC)
			return (handle_error(NULL_DATA, NULL));
	}
	return (CONTINUE_PROC);
}
