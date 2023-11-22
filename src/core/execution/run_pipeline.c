/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:50:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/22 17:09:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_pipeline(t_block **block, t_pipeline **ppl, int in_fd)
{
	t_uint		status;

	if ((*ppl)->next && (*ppl)->cmd->cmd[0])
	{
		if (pipe((*ppl)->process.pipefd) == -1)
			return (PIPE_FAIL);
		status = exec_cmd(block, ppl, in_fd, (*ppl)->process.pipefd[1]);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		is_any_proc_ended(block);
		return (run_pipeline(block, &(*ppl)->next, (*ppl)->process.pipefd[0]));
	}
	else if ((*ppl)->cmd->cmd[0])
	{
		status = exec_cmd(block, ppl, in_fd, STDOUT_FILENO);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		is_any_proc_ended(block);
		return (CONTINUE_PROC);
	}
	return (CONTINUE_PROC);
}

t_uint	processing(t_block **blocks)
{
	t_uint	status;

	status = run_pipeline(blocks, &((*blocks)->ppl), STDIN_FILENO);
	if (status != 0 && status != 1)
		return (handle_error(status, NULL));
	status = wait_all_proc(blocks);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
