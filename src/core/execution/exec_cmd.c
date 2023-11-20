/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/20 15:43:47 by  mchenava        ###   ########.fr       */
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
		child_sig();
		status = handle_redir(ppl, in_fd, out_fd);
		if (status != CONTINUE_PROC)
			exit (status);
		if (bi_id != 0)
			status = run_builtin(bi_id, ppl, true);
		else
			status = exec_bin(ppl);
		exit (status);
	}
	return (CONTINUE_PROC);
}
