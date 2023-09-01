/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:38:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/01 11:37:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	newfd(int oldfd, int newfd)
{
	int	status;

	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			return (errno);
		status = close_fd(oldfd);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	close_fd(int fd)
{
	t_uint	status;

	status = 0;
	if (fd >= 0)
	{
		status = close(fd);
		if (status != 0)
			return (status);
	}
	return (0);
}
