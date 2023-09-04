/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:09:23 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/04 10:50:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*add_paths_to_lst(t_sh_context *shx, char **paths)
{
	t_list	*lst_paths;
	int		i;

	i = -1;
	lst_paths = lst_create(shx, ft_strdup(paths[0]), i);
	if (!lst_paths)
		return (NULL);
	while (paths[++i])
	{
		lst_add_back(shx, &lst_paths, ft_strdup(paths[i]), i);
	}
	ft_free_tab(paths);
	return (lst_paths);
}

t_list	*complet_paths(t_sh_context *shx, char **paths)
{
	t_uint	i;
	t_uint	len;

	i = 0;
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
	return (add_paths_to_lst(shx, paths));
}

t_list	*get_path(t_sh_context *shx, char **env)
{
	t_uint	i;
	t_str	*paths;
	t_str	path;

	i = 0;
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
	return (complet_paths(shx, paths));
}
