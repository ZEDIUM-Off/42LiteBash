/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:02:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/22 22:58:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

bool	check_path(t_str *path)
{
	struct stat	path_stat;

	stat(*path, &path_stat);
	return (*path && access(*path, F_OK) == 0 && (path_stat.st_mode & S_IXUSR));
}

t_uint	test_with_path(t_sh_context *shx, t_str *cmd, t_str *path)
{
	t_list		*tmp;
	t_str		tmp_path;
	struct stat	pst;

	tmp = shx->lst_paths;
	if (stat(*path, &pst) && access(*path, F_OK) == 0 && pst.st_mode & S_IXUSR)
	{
		if (S_ISDIR(pst.st_mode))
			return (handle_error(CMD_NOT_FOUND, *path));
		*cmd = ft_strdup(shx, *path);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
		return (CONTINUE_PROC);
	}
	while (tmp)
	{
		tmp_path = ft_strjoin(shx, tmp->data, *path);
		if (!tmp_path)
			return (handle_error(MALLOC_FAIL, NULL));
		else if (check_path(&tmp_path))
			return (*cmd = ft_strdup(shx, tmp_path), CONTINUE_PROC);
		shx->gc->free(shx, tmp_path);
		tmp = tmp->next;
	}
	return (handle_error(CMD_NOT_FOUND, *path));
}

t_uint	test_for_file(t_sh_context *shx, t_str *cmd, t_str *path)
{
	struct stat	path_stat;

	stat(*path, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
		return (handle_error(IS_DIR, *path));
	if (*path && access(*path, F_OK) == 0)
	{
		if (path_stat.st_mode & S_IXUSR)
		{
			*cmd = ft_strdup(shx, *path);
			if (!*cmd)
				return (handle_error(MALLOC_FAIL, NULL));
			return (CONTINUE_PROC);
		}
		else
			return (handle_error(NO_PERM, *path));
	}
	else
		return (handle_error(CMD_NOT_FOUND, *path));
	return (CONTINUE_PROC);
}

t_uint	get_valid_paths(t_sh_context *shx, t_str *cmd, t_str src)
{
	t_uint		status;

	status = CONTINUE_PROC;
	if (ft_strcspn(src, "/") != ft_strlen(src))
		status = test_for_file(shx, cmd, &src);
	else
		status = test_with_path(shx, cmd, &src);
	return (status);
}
