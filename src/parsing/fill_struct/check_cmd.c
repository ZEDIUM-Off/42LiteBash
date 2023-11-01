/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:02:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/25 15:15:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	handle_quotes(t_sh_context *shx, t_str *splited,
	t_uint *i, t_str *to_build)
{
	t_uint	meta;

	meta = get_meta_char(&splited[*i][0]);
	if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
	{
		*i += 1;
		while (splited[*i] && get_meta_char(&splited[*i][0]) != meta)
		{
			*to_build = ft_strfjoin(shx, *to_build, splited[*i]);
			if (!*to_build)
				return (handle_error(MALLOC_FAIL, NULL));
			*i += 1;
		}
		*i += 1;
	}
	else
	{
		*to_build = ft_strfjoin(shx, *to_build, splited[*i]);
		if (!*to_build)
			return (handle_error(MALLOC_FAIL, NULL));
		*i += 1;
	}
	return (CONTINUE_PROC);
}

t_uint	build_command(t_sh_context *shx, t_str *splited,
	t_uint *i, t_str *to_build)
{
	t_uint	status;

	while (splited[*i])
	{
		status = handle_quotes(shx, splited, i, to_build);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (splited[*i] && splited[*i][0] == '\0')
		{
			*i += 1;
			continue ;
		}
		return (CONTINUE_PROC);
	}
	return (CONTINUE_PROC);
}

t_uint	test_src_path(t_sh_context *shx, t_str *cmd, t_str src)
{
	struct stat	path_stat;

	if (src && access(src, X_OK) == 0)
	{
		*cmd = ft_strdup(shx, src);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	stat(src, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
		return (handle_error(IS_DIR, src));
	return (CONTINUE_PROC);
}

t_uint	get_valid_paths(t_sh_context *shx, t_str *cmd, t_str src)
{
	t_list		*tmp;
	struct stat	path_stat;
	t_uint		status;

	status = test_src_path(shx, cmd, src);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	tmp = shx->lst_paths;
	while (tmp)
	{
		*cmd = ft_strjoin(shx, tmp->data, src);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
		stat(*cmd, &path_stat);
		if (S_ISDIR(path_stat.st_mode))
			return (handle_error(IS_DIR, src));
		if (access(*cmd, X_OK) == 0)
			return (CONTINUE_PROC);
		shx->gc->free(shx, *cmd);
		tmp = tmp->next;
	}
	return (handle_error(CMD_NOT_FOUND, src));
}
