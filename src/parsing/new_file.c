/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:42:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/05 00:08:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	test_file(t_str file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (printf ("file error : %d\n", errno), errno);
	close(fd);
	return (0);
}

t_uint	new_file(t_file *file, t_str name)
{
	t_uint	status;

	printf ("new_file, name = %s\n", name);
	status = test_file(name);
	if (status != 0)
		return (status);
	file->file_name = strdup(name);
	if (!file->file_name)
		return (MALLOC_FAIL);
	file->fd = -1;
	file->is_open = false;
	return (0);
}
