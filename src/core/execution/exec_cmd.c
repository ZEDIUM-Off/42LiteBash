/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:39:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/24 13:35:55 by  mchenava        ###   ########.fr       */
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
	t_uint	status;

	printf("exec_bin\n");
	status = handle_chunck(&((*ppl)->cmd->chunk));
	if (status != 0)
		return (status);
	printf("---------------------------- cmd result ----------------------------\n");
	status = execve((*ppl)->cmd->cmd[0], (*ppl)->cmd->cmd, g_shx->env);
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
	return (status);
}
