/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:11:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/01 12:27:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	handle_sigchld(int sig)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (pid > 0)
		printf("Le processus enfant %d a terminé avec le signal : %d\n", pid, sig);
}

t_uint	check_proc_status(t_block **block)
{
	t_pipeline		*ppl;

	ppl = (*block)->ppl;
	while (ppl)
	{
		if (ppl->process.status == -42)
			return (PROC_NOT_TERMINATED + ppl->process.pid);
		ppl = ppl->next;
	}
	(*block)->shx->proc_nb = 0;
	return (0);
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
	pid_t			pid;
	int				status;

	shx = (*block)->shx;
	while (shx->proc_nb > 0)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			return (check_proc_status(block));
		while (pid > 0)
		{
			update_proc(block, status, pid);
			pid = waitpid(-1, &status, 0);
		}
	}
	return (0);
}

void	update_proc(t_block **block, int status, pid_t pid)
{
	t_sh_context	*shx;
	t_pipeline		*ppl;
	bool			proc_found;

	ppl = (*block)->ppl;
	shx = (*block)->shx;
	while (ppl && !proc_found)
	{
		if (ppl->process.pid == pid)
		{
			proc_found = true;
			if (WIFEXITED(status))
				ppl->process.status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				ppl->process.status = WTERMSIG(status);
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

	shx = (*block)->shx;
	if (shx->proc_nb >= MAX_PROC_NB)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
			update_proc(block, status, pid);
	}
}