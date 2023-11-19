/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:02:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 17:17:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	test_with_path(t_sh_context *shx, t_str *cmd, t_str *path, bool *found)
{
	if (*path && access(*path, F_OK) == 0)
	{
		if (access(*path, X_OK) != 0)
			return (handle_error(NO_PERM, *path));
		*found = true;
		*cmd = ft_strdup(shx, *path);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
		printf("test_with_path cmd: %s\n", *cmd);
		printf("test_with_path path: %s\n", *path);
		printf("test_with_path found: %d\n", *found);
	}
	return (CONTINUE_PROC);
}

t_uint	test_no_path(t_sh_context *shx, t_str *cmd, t_str *path, bool *found)
{
	if (*path && access(*path, F_OK) == 0)
	{
		if (access(*path, X_OK) != 0)
			return (handle_error(CMD_NOT_FOUND, *path));
		*found = true;
		*cmd = ft_strdup(shx, *path);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	printf("test_no_path cmd: %s\n", *cmd);
	printf("test_no_path path: %s\n", *path);
	printf("test_no_path found: %d\n", *found);
	return (CONTINUE_PROC);
}

t_uint	test_access(t_sh_context *shx, t_str *cmd, t_str *path, bool *found)
{
	struct stat	path_stat;

	stat(*path, &path_stat);
	printf("test_access path: %s\n", *path);
	printf("test_access ft_strcspn(*path, /): %ld\n", ft_strcspn(*path, "/"));
	printf("test_access ft_strlen(*path): %ld\n", ft_strlen(*path));
	if (ft_strcspn(*path, "/") == ft_strlen(*path))
	{
		if (S_ISDIR(path_stat.st_mode))
			return (handle_error(CMD_NOT_FOUND, *path));
		return (test_no_path(shx, cmd, path, found));
	}
	else
	{
		if (S_ISDIR(path_stat.st_mode))
			return (handle_error(NO_PERM, *path));
		return (test_with_path(shx, cmd, path, found));
	}
	return (CONTINUE_PROC);
}

t_uint	get_valid_paths(t_sh_context *shx, t_str *cmd, t_str src)
{
	t_list		*tmp;
	t_uint		status;
	bool		found;

	status = test_access(shx, cmd, &src, &found);
	printf("status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (found)
		return (CONTINUE_PROC);
	printf("PASS in get_valid_paths found\n");
	tmp = shx->lst_paths;
	while (tmp)
	{
		*cmd = ft_strjoin(shx, tmp->data, src);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
		status = test_access(shx, cmd, cmd, &found);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		else if (found)
			return (CONTINUE_PROC);
		shx->gc->free(shx, *cmd);
		tmp = tmp->next;
	}
	return (handle_error(CMD_NOT_FOUND, src));
}
