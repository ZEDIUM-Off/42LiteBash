/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:09:23 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 16:35:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*add_paths_to_lst(t_sh_context *shx, char **paths)
{
	t_list	*lst_paths;
	int		i;

	i = -1;
	trace(shx, "add_paths_to_lst", "every things is in the name", PARSE);
	lst_paths = lst_create(shx, ft_strdup(paths[0]), i);
	if (!lst_paths)
		return (NULL);
	while (paths[++i])
	{
		lst_add_back(shx, &lst_paths, ft_strdup(paths[i]), i);
	}
	ft_free_tab(paths);
	log_action(shx);
	return (lst_paths);
}

t_list	*complet_paths(t_sh_context *shx, char **paths)
{
	t_uint	i;
	t_uint	len;

	i = 0;
	trace(shx, "complet_path", "complet the paths with / at end", PARSE);
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
	log_action(shx);
	return (add_paths_to_lst(shx, paths));
}

t_list	*get_path(t_sh_context *shx, char **env)
{
	t_uint	i;
	t_str	*paths;
	t_str	path;

	i = 0;
	trace(shx, "get_path", "pars the path from envp", PARSE);
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
	log_action(shx);
	return (complet_paths(shx, paths));
}
