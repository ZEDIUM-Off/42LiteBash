/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:42:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 14:00:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	test_file(t_str file_name, t_uint type)
{
	int	fd;

	if (!file_name)
		return (handle_error(NULL_DATA, NULL));
	if (type == IN_REDIRECT)
		fd = open(file_name, O_RDONLY);
	else
		fd = open(file_name, O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		return (handle_error(OPEN_FAIL, file_name));
	return (close_fd(fd));
}

t_uint	new_file(t_sh_context *shx, t_file *file, t_str name, t_uint type)
{
	t_uint	status;

	if (type != HERE_DOC)
	{
		status = test_file(name, type);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	file->file_name = ft_strdup(shx, name);
	if (!file->file_name)
		return (handle_error(MALLOC_FAIL, NULL));
	file->fd = -1;
	file->is_open = false;
	return (CONTINUE_PROC);
}
