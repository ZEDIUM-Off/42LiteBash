/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:02:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/14 18:30:00 by  mchenava        ###   ########.fr       */
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
	return (CONTINUE_PROC);
}

t_uint	test_access(t_sh_context *shx, t_str *cmd, t_str *path, bool *found)
{
	struct stat	path_stat;

	stat(*path, &path_stat);
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
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (found)
		return (CONTINUE_PROC);
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
