/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 13:56:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	exec_bin(t_pipeline	**ppl)
{
	t_sh_context	*shx;

	shx = (*ppl)->shx;
	if (execve((*ppl)->cmd->cmd[0], (*ppl)->cmd->cmd, shx->envp) == -1)
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

void	child_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

t_uint	child_process(t_pipeline **ppl, int in_fd, int out_fd, t_uint bi_id)
{
	t_uint	status;

	close_fd((*ppl)->process.pipefd[0]);
	status = handle_redir(ppl, in_fd, out_fd);
	if (status != CONTINUE_PROC)
		exit (status);
	child_sig();
	if (bi_id != 0)
		status = run_builtin(bi_id, ppl, true);
	else if ((*ppl)->cmd->cmd[0])
		status = exec_bin(ppl);
	gc_free_all((*ppl)->shx);
	exit (status);
	return (status);
}

t_uint	parent_process(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	status = close_fd((*ppl)->process.pipefd[1]);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = close_fd(in_fd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
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
	if ((*ppl)->cmd->execute == false)
		return (CONTINUE_PROC);
	(*ppl)->process.pid = fork();
	if ((*ppl)->process.pid == -1)
		return (FORK_FAIL);
	(*ppl)->shx->proc_nb++;
	if ((*ppl)->process.pid == 0)
		status = child_process(ppl, in_fd, out_fd, bi_id);
	else
		status = parent_process(ppl, in_fd);
	return (status);
}
