/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:42:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 14:32:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	test_file(t_str file_name, t_uint type)
{
	int	fd;

	if (!file_name)
		return (NO_FILE_NAME);
	if (type == IN_REDIRECT)
		fd = open(file_name, O_RDONLY);
	else
		fd = open(file_name, O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		return (printf ("file error : %d\n", errno), errno);
	close(fd);
	return (0);
}

t_uint	new_file(t_sh_context *shx, t_file *file, t_str name, t_uint type)
{
	t_uint	status;

	status = test_file(name, type);
	if (status != 0)
		return (status);
	file->file_name = ft_strdup(shx, name);
	if (!file->file_name)
		return (MALLOC_FAIL);
	file->fd = -1;
	file->is_open = false;
	return (0);
}
