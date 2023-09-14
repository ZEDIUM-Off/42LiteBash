/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:39:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/14 01:48:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	default_ppl_redir(t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint	status;

	status = 0;
	if (in_fd != STDIN_FILENO && (*ppl)->redir.in_type == NONE)
	{
		printf("in_fd = %d\n", in_fd);
		status = newfd(in_fd, STDIN_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (out_fd != STDOUT_FILENO && (*ppl)->redir.out_type == NONE)
	{
		printf("out_fd = %d\n", out_fd);
		status = newfd(out_fd, STDOUT_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	infile_redir(t_pipeline **ppl)
{
	t_uint	status;

	if ((*ppl)->redir.in_type != NONE)
	{
		if ((*ppl)->redir.in_type == HERE_DOC)
		{
			status = handle_here_doc(ppl);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		status = open_file(&(*ppl)->redir.infile, (*ppl)->redir.in_type);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = newfd((*ppl)->redir.infile.fd, STDIN_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	outfile_redir(t_pipeline **ppl)
{
	t_uint	status;

	if ((*ppl)->redir.out_type != NONE)
	{
		status = open_file(&(*ppl)->redir.outfile, (*ppl)->redir.out_type);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = newfd((*ppl)->redir.outfile.fd, STDOUT_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	handle_redir(t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint	status;

	status = 0;
	status = default_ppl_redir(ppl, in_fd, out_fd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = infile_redir(ppl);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = outfile_redir(ppl);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
