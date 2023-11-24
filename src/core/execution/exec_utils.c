/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:26:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 15:16:23 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	ft_strdup2(t_str s)
{
	t_str	new_s;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new_s = (t_str)malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

t_str	*ft_dup_tab(t_str *tabl)
{
	t_str	*new_tab;
	int		i;

	i = 0;
	while (tabl[i])
		i++;
	new_tab = (t_str *)malloc(sizeof(t_str) * (i + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tabl[i])
	{
		new_tab[i] = ft_strdup2(tabl[i]);
		if (!new_tab[i])
			return (NULL);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

t_uint	clean_before_exec(t_sh_context *shx, t_pipeline **ppl, t_str	**cmd)
{
	*cmd = ft_dup_tab((*ppl)->cmd->cmd);
	if (!*cmd)
		return (MALLOC_FAIL);
	gc_free_all(shx);
	return (CONTINUE_PROC);
}

void	free_tab_str(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
	return ;
}
