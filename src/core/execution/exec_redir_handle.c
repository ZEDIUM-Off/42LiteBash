/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:39:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/01 12:02:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	open_file(t_file *file, t_uint type)
{
	if (type == IN_REDIRECT || type == OUT_REDIRECT)
	{
		file->fd = open(file->file_name, O_RDWR | O_CREAT, 0644);
		if (file->fd == -1)
			return (errno);
		file->is_open = true;
	}
	else if (type == APPEND_REDIRECT)
	{
		file->fd = open(file->file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (file->fd == -1)
			return (errno);
		file->is_open = true;
	}
	return (0);
}

t_uint	default_ppl_redir(int in_fd, int out_fd)
{
	t_uint	status;

	status = 0;
	if (in_fd != STDIN_FILENO)
	{
		status = newfd(in_fd, STDIN_FILENO);
		if (status != 0)
			return (status);
	}
	if (out_fd != STDOUT_FILENO)
	{
		status = newfd(out_fd, STDOUT_FILENO);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	infile_redir(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	if ((*ppl)->redir.in_type != NONE)
	{
		printf("there is a redir infile\n");
		if ((*ppl)->redir.in_type == HERE_DOC)
			status = here_doc(&(*ppl)->redir.infile);
		else
			status = open_file(&(*ppl)->redir.infile, (*ppl)->redir.in_type);
		if (status != 0)
			return (status);
		status = newfd((*ppl)->redir.infile.fd, in_fd);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	outfile_redir(t_pipeline **ppl, int out_fd)
{
	t_uint	status;

	if ((*ppl)->redir.out_type != NONE)
	{
		printf("there is a redir out\n");
		status = open_file(&(*ppl)->redir.outfile, (*ppl)->redir.out_type);
		if (status != 0)
			return (status);
		status = newfd((*ppl)->redir.outfile.fd, out_fd);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	handle_redir(t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint	status;

	status = 0;
	status = default_ppl_redir(in_fd, out_fd);
	if (status != 0)
		return (status);
	status = infile_redir(ppl, in_fd);
	if (status != 0)
		return (status);
	status = outfile_redir(ppl, out_fd);
	if (status != 0)
		return (status);
	return (0);
}
