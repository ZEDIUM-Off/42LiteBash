/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:39:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/24 13:31:18 by  mchenava        ###   ########.fr       */
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

t_uint	here_doc(t_file	*file)
{
	(void)file;
	return (0);
}

t_uint	handle_redir(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	printf("handle_redir\n");
	status = 0;
	status = newfd(in_fd, STDIN_FILENO);
	if (status != 0)
		return (status);
	printf("in_fd = %d\n", in_fd);
	if ((*ppl)->redir.in_type != NONE)
	{
		printf("there is a redir in\n");
		if ((*ppl)->redir.in_type == HERE_DOC)
			status = here_doc(&(*ppl)->redir.infile);
		else
			status = open_file(&(*ppl)->redir.infile, (*ppl)->redir.in_type);
		if (status != 0)
			return (status);
		status = newfd((*ppl)->redir.infile.fd, STDIN_FILENO);
		if (status != 0)
			return (status);
	}
	status = newfd(STDOUT_FILENO, STDOUT_FILENO);
	if (status != 0)
		return (status);
	// printf("out_fd = %d\n", (*ppl)->process.pipefd[1]);
	if ((*ppl)->redir.out_type != NONE)
	{
		printf("there is a redir out\n");
		if ((*ppl)->redir.out_type == APPEND_REDIRECT)
			status = open_file(&(*ppl)->redir.outfile, (*ppl)->redir.out_type);
		else
			status = open_file(&(*ppl)->redir.outfile, (*ppl)->redir.out_type);
		if (status != 0)
			return (status);
		status = newfd((*ppl)->redir.outfile.fd, STDOUT_FILENO);
		if (status != 0)
			return (status);
	}
	return (0);
}
