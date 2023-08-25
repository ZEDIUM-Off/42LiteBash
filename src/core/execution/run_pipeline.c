/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:50:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/25 12:52:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	child_process(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	printf("child_process\n");
	status = close_fd((*ppl)->process.pipefd[0]);
	if (status != 0)
		return (status);
	status = handle_redir(ppl, in_fd);
	if (status != 0)
		return (status);
	status = exec_cmd(ppl);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	parent_process(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	printf("parent_process\n");
	status = close_fd((*ppl)->process.pipefd[1]);
	if (status != 0)
		return (status);
	if (in_fd >= 0)
	{
		status = close_fd(in_fd);
		if (status != 0)
			return (status);
	}
	status = run_pipeline(&((*ppl)->next), (*ppl)->process.pipefd[0]);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	last_process(t_pipeline **ppl, int in_fd)
{
	t_uint	status;

	printf("last_process\n");
	status = handle_redir(ppl, in_fd);
	if (status != 0)
		return (printf("status : %u\n", status), status);
	status = exec_cmd(ppl);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	run_pipeline(t_pipeline **ppl, int in_fd)
{
	t_uint		status;

	if (!(*ppl)->next)
	{
		status = last_process(ppl, in_fd);
		printf("last status = %u\n", status);
		if (status != 0)
			return (status);
	}
	else
	{
		if (g_shx->proc_count >= MAX_PROC)
			wait_for_proc();
		if (pipe((*ppl)->process.pipefd) == -1)
			return (PIPE_FAIL);
		(*ppl)->process.pid = fork();
		if ((*ppl)->process.pid == -1)
			return (FORK_FAIL);
		g_shx->proc_count++;
		if ((*ppl)->process.pid == 0)
		{
			status = child_process(ppl, in_fd);
			printf("child status = %u\n", status);
			if (status != 0)
				return (status);
		}
		else
		{
			status = parent_process(ppl, in_fd);
			printf("parent status = %u\n", status);
			if (status != 0)
				return (status);
		}
	}
	return (0);
}

t_uint	processing(t_block **blocks)
{
	t_block	*_blocks;
	t_uint	status;

	_blocks = *blocks;
	printf("processing\n");
	while (_blocks)
	{
		status = run_pipeline(&(_blocks->ppl), STDIN_FILENO);
		if (status != 0 && status != 1)
			return (status);
		_blocks->exec_result = status;
		_blocks = _blocks->next;
	}
	return (0);
}
