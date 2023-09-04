/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:33:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 23:48:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	open_file(t_file *file, t_uint type)
{
	if (type == IN_REDIRECT || type == HERE_DOC)
	{
		file->fd = open(file->file_name, O_RDONLY | O_CREAT, 0644);
		if (file->fd == -1)
			return (errno);
		file->is_open = true;
	}
	else if (type == OUT_REDIRECT)
	{
		file->fd = open(file->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			return (errno);
		file->is_open = true;
	}
	else if (type == APPEND_REDIRECT)
	{
		file->fd = open(file->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (file->fd == -1)
			return (errno);
		file->is_open = true;
	}
	return (0);
}

t_uint	close_files(t_pipeline **ppl)
{
	if ((*ppl)->redir.infile.is_open)
	{
		if (close((*ppl)->redir.infile.fd) == -1)
			return (errno);
		(*ppl)->redir.infile.is_open = false;
	}
	if ((*ppl)->redir.outfile.is_open)
	{
		if (close((*ppl)->redir.outfile.fd) == -1)
			return (errno);
		(*ppl)->redir.outfile.is_open = false;
	}
	return (0);
}