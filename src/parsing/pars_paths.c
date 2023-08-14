/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:09:23 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/14 17:46:43 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*add_paths_to_lst(char **paths)
{
	t_list	*lst_paths;
	int		i;

	i = -1;
	trace("add_paths_to_lst", "every things is in the name", PARSE);
	lst_paths = lst_create(ft_strdup(paths[0]), i);
	while (paths[++i])
	{
		lst_add_back(&lst_paths, ft_strdup(paths[i]), i);
	}
	ft_free_tab(paths);
	log_action();
	return (lst_paths);
}

t_list	*complet_paths(char **paths)
{
	t_uint	i;
	t_uint	len;

	i = 0;
	trace("complet_path", "complet the paths with / at end", PARSE);
	while (paths[i])
	{
		len = ft_strlen(paths[i]) - 1;
		if (paths[i][len] != '/')
		{
			paths[i] = ft_strfjoin(paths[i], "/");
			if (!paths)
				return (ft_free_tab(paths), NULL);
		}
		i++;
	}
	i = 0;
	log_action();
	return (add_paths_to_lst(paths));
}

t_list	*get_path(char **env)
{
	t_uint	i;
	t_str	*paths;
	t_str	path;

	i = 0;
	trace("get_path", "pars the path from envp", PARSE);
	path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			path = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	path += 5;
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	log_action();
	return (complet_paths(paths));
}

