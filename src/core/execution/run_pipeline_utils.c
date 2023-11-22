/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:38:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 17:04:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	newfd(int oldfd, int newfd)
{
	int	status;

	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			return (handle_error(DUP_FAIL, NULL));
		printf ("(child)close old %d\n", oldfd);
		status = close_fd(oldfd);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	close_fd(int fd)
{
	printf ("close_fd : fd = %d\n", fd);
	if (fd >= 0)
	{
		if (close(fd) == -1)
			return (handle_error(CLOSE_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}
