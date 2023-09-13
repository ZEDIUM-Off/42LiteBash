/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:50:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 14:14:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_pipeline(t_block **block, t_pipeline **ppl, int in_fd)
{
	t_uint		status;

	if ((*ppl)->next)
	{
		if (pipe((*ppl)->process.pipefd) == -1)
			return (PIPE_FAIL);
		status = exec_cmd(block, ppl, in_fd, (*ppl)->process.pipefd[1]);
		if (status != 0)
			return (status);
		status = close_fd((*ppl)->process.pipefd[1]);
		if (status != 0)
			return (status);
		is_any_proc_ended(block);
		return (run_pipeline(block, &(*ppl)->next, (*ppl)->process.pipefd[0]));
	}
	else
	{
		status = exec_cmd(block, ppl, in_fd, STDOUT_FILENO);
		if (status != 0)
			return (status);
		is_any_proc_ended(block);
		return (0);
	}
	return (0);
}

t_uint	processing(t_block **blocks)
{
	t_uint	status;

	status = run_pipeline(blocks, &((*blocks)->ppl), STDIN_FILENO);
	if (status != 0 && status != 1)
		return (status);
	status = wait_all_proc(blocks);
	if (status != 0)
		return (status);
	return (0);
}
