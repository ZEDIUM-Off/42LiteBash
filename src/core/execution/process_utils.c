/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:11:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 16:03:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_proc_status(t_block **block)
{
	t_pipeline		*ppl;

	ppl = (*block)->ppl;
	while (ppl)
	{
		if (ppl->process.status == -42)
			return (STOP_PROC);
		g_exit_status = ppl->process.status;
		ppl = ppl->next;
	}
	(*block)->shx->proc_nb = 0;
	return (CONTINUE_PROC);
}

void	is_any_proc_ended(t_block **block)
{
	int				status;
	pid_t			pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (pid > 0)
		update_proc(block, status, pid);
}

t_uint	wait_all_proc(t_block **block)
{
	t_sh_context	*shx;
	t_pipeline		*ppl;
	pid_t			pid;
	int				status;

	shx = (*block)->shx;
	while (shx->proc_nb > 0)
	{
		ppl = (*block)->ppl;
		while (ppl)
		{
			if (ppl->process.status == -42)
			{
				pid = waitpid(ppl->process.pid, &status, WNOHANG);
				if (pid == -1 && errno != ECHILD)
					return (WAITPID_FAIL);
				if (pid > 0)
					update_proc(block, status, pid);
				// if (ppl->next && ppl->next->process.status != -42)
				// {
				// 	close_files(&ppl);
				// 	// printf("clossing pipesfd for : %s\n", ppl->cmd->cmd[0]);
				// 	if (ppl->process.pipefd[0] > 2)
				// 		close(ppl->process.pipefd[0]);
				// 	if (ppl->process.pipefd[1] > 2)
				// 		close(ppl->process.pipefd[1]);
				// }
			}
			ppl = ppl->next;
		}
	}
	return (check_proc_status(block));
}

void	update_proc(t_block **block, int status, pid_t pid)
{
	t_sh_context	*shx;
	t_pipeline		*ppl;
	bool			proc_found;

	ppl = (*block)->ppl;
	shx = (*block)->shx;
	proc_found = 0;
	while (ppl && !proc_found)
	{
		if (ppl->process.pid == pid)
		{
			printf ("updating process :%s\n", ppl->cmd->cmd[0]);
			proc_found = true;
			if (WIFEXITED(status))
				ppl->process.status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				ppl->process.status = WTERMSIG(status);
			close_files(&ppl);
			if (ppl->process.pipefd[0] > 2)
				close(ppl->process.pipefd[0]);
			if (ppl->process.pipefd[1] > 2)
				close(ppl->process.pipefd[1]);
			shx->proc_nb--;
		}
		ppl = ppl->next;
	}
}

void	wait_any_proc(t_block **block)
{
	t_sh_context	*shx;
	int				status;
	pid_t			pid;

	signal(SIGINT, SIG_IGN);
	shx = (*block)->shx;
	if (shx->proc_nb >= MAX_PROC_NB)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
			update_proc(block, status, pid);
	}
}
