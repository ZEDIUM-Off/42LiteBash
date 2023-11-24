/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:39:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 13:43:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	default_ppl_redir(t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint	status;

	status = CONTINUE_PROC;
	if (in_fd != STDIN_FILENO && (*ppl)->redir.in_type == NONE)
	{
		status = newfd(in_fd, STDIN_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (out_fd != STDOUT_FILENO && (*ppl)->redir.out_type == NONE)
	{
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
			status = here_doc((*ppl)->shx, &(*ppl)->redir.here_doc_txt,
					(*ppl)->redir.infile.file_name);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			status = handle_here_doc(ppl);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		status = open_file(&(*ppl)->redir.infile, (*ppl)->redir.in_type);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if ((*ppl)->redir.infile.fd != -1)
		{
			status = newfd((*ppl)->redir.infile.fd, STDIN_FILENO);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
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
		if ((*ppl)->redir.outfile.fd != -1)
		{
			status = newfd((*ppl)->redir.outfile.fd, STDOUT_FILENO);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
	}
	return (CONTINUE_PROC);
}

t_uint	handle_redir(t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint	status;
	t_str	*cmd_no_redir;

	status = CONTINUE_PROC;
	cmd_no_redir = (t_str *)(*ppl)->shx->gc->malloc((*ppl)->shx, sizeof(t_str)
			* ((*ppl)->size + 1), false);
	if (!cmd_no_redir)
		return (handle_error(MALLOC_FAIL, NULL));
	status = extract_redirect(ppl, &cmd_no_redir,
			(*ppl)->cmd->cmd, (*ppl)->cmd->size);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	gc_free((*ppl)->shx, (*ppl)->cmd->cmd);
	(*ppl)->cmd->cmd = cmd_no_redir;
	status = default_ppl_redir(ppl, in_fd, out_fd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = infile_redir(ppl);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = outfile_redir(ppl);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = no_quotes_cmd((*ppl)->shx, &(*ppl)->cmd);
	return (status);
}
