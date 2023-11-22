/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:33:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 16:55:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	open_file(t_file *file, t_uint type)
{
	if (type == IN_REDIRECT || type == HERE_DOC)
	{
		file->fd = open(file->file_name, O_RDONLY, 0644);
		if (file->fd == -1)
			return (STOP_PROC);
		file->is_open = true;
	}
	else if (type == OUT_REDIRECT)
	{
		file->fd = open(file->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			return (STOP_PROC);
		file->is_open = true;
	}
	else if (type == APPEND_REDIRECT)
	{
		file->fd = open(file->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (file->fd == -1)
			return (STOP_PROC);
		file->is_open = true;
	}
	return (CONTINUE_PROC);
}

t_uint	close_files(t_pipeline **ppl)
{
	printf ("close files : infd = %d, out = %d\n", (*ppl)->redir.infile.fd, (*ppl)->redir.outfile.fd);
	if ((*ppl)->redir.infile.fd > 2 && (*ppl)->redir.infile.is_open)
	{
		if (close((*ppl)->redir.infile.fd) == -1)
			return (handle_error(CLOSE_FAIL, (*ppl)->redir.infile.file_name));
		(*ppl)->redir.infile.is_open = false;
	}
	if ((*ppl)->redir.outfile.fd > 2 && (*ppl)->redir.outfile.is_open)
	{
		if (close((*ppl)->redir.outfile.fd) == -1)
			return (handle_error(CLOSE_FAIL, (*ppl)->redir.outfile.file_name));
		(*ppl)->redir.outfile.is_open = false;
	}
	return (CONTINUE_PROC);
}
