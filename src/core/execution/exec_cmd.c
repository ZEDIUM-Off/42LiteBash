/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/13 18:31:31 by bfaure           ###   ########lyon.fr   */
=======
/*   Updated: 2023/09/14 01:07:27 by  mchenava        ###   ########.fr       */
>>>>>>> 17ba17eea1caa33a08e9b4dc7a709fb4f5c81459
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	handle_chunck(t_chunk **chunk)
{
	t_uint	status;

	status = 0;
	if ((*chunk) && (*chunk)->blocks)
	{
		status = processing(&(*chunk)->blocks);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if ((*chunk) && (*chunk)->under_chunk)
	{
		status = handle_chunck(&(*chunk)->under_chunk);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	exec_bin(t_pipeline	**ppl)
{
	t_uint			status;
	t_sh_context	*shx;

	shx = (*ppl)->shx;
	status = handle_chunck(&((*ppl)->cmd->chunk));
	if (status != CONTINUE_PROC)
		exit (EXIT_FAILURE);
	if (execve((*ppl)->cmd->cmd[0], (*ppl)->cmd->cmd, shx->env) == -1)
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

t_uint	exec_cmd(t_block **block, t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint			status;
	t_uint			bi_id;

	bi_id = check_builtins((*ppl)->cmd->cmd[0]);
	status = check_no_fork_bi(bi_id, ppl);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	wait_any_proc(block);
	(*ppl)->process.pid = fork();
	if ((*ppl)->process.pid == -1)
		return (FORK_FAIL);
	(*ppl)->shx->proc_nb++;
	if ((*ppl)->process.pid == 0)
	{
		status = handle_redir(ppl, in_fd, out_fd);
		if (status != CONTINUE_PROC)
			exit (EXIT_FAILURE);
		if (bi_id != 0)
			status = run_builtin(bi_id, ppl, true);
		else
			status = exec_bin(ppl);
		if (status != CONTINUE_PROC)
			exit (EXIT_FAILURE);
		exit (EXIT_SUCCESS);
	}
	return (CONTINUE_PROC);
}
