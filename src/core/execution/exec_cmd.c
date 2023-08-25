/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/25 13:12:44 by  mchenava        ###   ########.fr       */
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

t_uint	execve_forked(t_pipeline **ppl)
{
	pid_t	pid;
	int		proc_status;
	t_uint	status;

	pid = fork();
	if (pid == -1)
		return (FORK_FAIL);
	else if (pid > 0)
	{
		waitpid(pid, &proc_status, 0);
		if (WIFEXITED(proc_status))
		{
			status = WEXITSTATUS(proc_status);
			printf("Le statut de sortie du programme est %d\n", status);
			return (status);
		}
	}
	else
	{
		if (execve((*ppl)->cmd->cmd[0], (*ppl)->cmd->cmd, g_shx->env) == -1)
			return (EXECVE_FAIL);
	}
	return (0);
}

t_uint	exec_bin(t_pipeline	**ppl)
{
	t_uint	status;

	printf("exec_bin\n");
	status = handle_chunck(&((*ppl)->cmd->chunk));
	if (status != 0)
		return (status);
	printf("---------------------------- #cmd result# ----------------------------\n");
	status = execve_forked(ppl);
	printf("exec bin status = %u\n", status);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	exec_cmd(t_pipeline **ppl)
{
	t_uint	status;
	t_uint	bi_id;

	printf("exec_cmd\n");
	printf ("cmd = %s\n", (*ppl)->cmd->cmd[0]);
	bi_id = check_builtins((*ppl)->cmd->cmd[0]);
	if (bi_id != 0)
		status = run_builtin(bi_id, ppl);
	else
		status = exec_bin(ppl);
	printf("exec cmd status = %u\n", status);
	return (status);
}
