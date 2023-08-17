/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:50:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/16 12:43:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_uint	process_command(t_command **cmd)
{
	t_command	*_cmd;
	t_uint		status;

	_cmd = *cmd;
	if (_cmd->type == CMD_BUILTIN)
	{
		status = process_builtin(&_cmd->builtin);
		if (status != 0)
			return (status);
	}
	else if (_cmd->type == CMD_EXEC)
	{
		status = process_exec(&_cmd->exec);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	run_pipeline(t_pipeline **ppl)
{
	t_uint		status;

	if (!ppl->next)
	{
		status = last_process(block);
		if (status != 0)
			return (status);
	}
	else
	{
		if (g_shx->proc_count >= MAX_PROC)
			wait_for_proc();
		if (pipe(ppl->process.pipefd) == -1)
			return (PIPE_FAIL);
		ppl->process.pid = fork();
		if (ppl->process.pid == -1)
			return (FORK_FAIL);
		if (ppl->process.pid == 0)
		{
			status = child_process(block);
			if (status != 0)
				return (status);
		}
		else
		{
			status = parent_process(block);
			if (status != 0)
				return (status);
		}
	}
	return (0);
}

t_uint	process_pipeline(t_block **block)
{
	t_pipeline	*_ppl;
	t_uint		status;

	_ppl = (*block)->ppl;
	status = run_pipeline(&_ppl);
	return (0);
}

t_uint	processing(t_block **blocks)
{
	t_block	*_blocks;
	t_uint	status;

	_blocks = *blocks;
	while (_blocks)
	{
		status = process_pipeline(&_blocks->ppl);
		if (status != 0)
			return (status);
		_blocks = _blocks->next;
	}
	return (0);
}
