/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 13:08:30 by  mchenava        ###   ########.fr       */
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
		if (status != 0)
			return (status);
	}
	if ((*chunk) && (*chunk)->under_chunk)
	{
		status = handle_chunck(&(*chunk)->under_chunk);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	exec_bin(t_pipeline	**ppl)
{
	t_uint			status;
	t_sh_context	*shx;

	shx = (*ppl)->shx;
	status = handle_chunck(&((*ppl)->cmd->chunk));
	if (status != 0)
		exit (status);
	if (execve((*ppl)->cmd->cmd[0], (*ppl)->cmd->cmd, shx->env) == -1)
		exit (errno);
	exit (0);
}

t_uint	exec_cmd(t_block **block, t_pipeline **ppl, int in_fd, int out_fd)
{
	t_uint			status;
	t_uint			bi_id;

	status = 0;
	printf("exec_cmd : %s\n", (*ppl)->cmd->cmd[0]);
	bi_id = check_builtins((*ppl)->cmd->cmd[0]);
	check_exit(bi_id, ppl);
	wait_any_proc(block);
	(*ppl)->process.pid = fork();
	if ((*ppl)->process.pid == -1)
		return (FORK_FAIL);
	(*ppl)->shx->proc_nb++;
	if ((*ppl)->process.pid == 0)
	{
		status = handle_redir(ppl, in_fd, out_fd);
		if (status != 0)
			exit(status);
		if (bi_id != 0)
			status = run_builtin(bi_id, ppl);
		else
			status = exec_bin(ppl);
		exit(status);
	}
	return (0);
}
