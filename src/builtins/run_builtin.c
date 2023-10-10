/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:43:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/10 11:40:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl, bool fork)
{
	t_uint			status;

	status = 0;
	if (bi_id == ECHO_BI)
		status = exec_echo(&(*ppl)->cmd);
	else if (bi_id == PWD_BI)
		status = pwd_builtins();
	else if (bi_id == CD_BI)
		status = cd_builtins((*ppl)->shx, (*ppl)->cmd->cmd[1]);
	else if (bi_id == EXPORT_BI && !fork)
		status = export_cmd(&(*ppl)->cmd);
	else if (bi_id == UNSET_BI && !fork)
		status = unset_cmd(&(*ppl)->cmd);
	else if (bi_id == ENV_BI)
		status = lst_print(&(*ppl)->shx->envp, "%s\n");
	else if (bi_id == EXIT_BI && !fork)
		exit_shell((*ppl)->shx, 420);
	if (status != CONTINUE_PROC)
	{
		if (fork)
			exit (EXIT_FAILURE);
		return (handle_error(status, NULL));
	}
	if (fork)
		exit (EXIT_SUCCESS);
	return (CONTINUE_PROC);
}

t_uint	check_no_fork_bi(t_uint bi_id, t_pipeline **ppl)
{
	if (bi_id == EXIT_BI
		|| bi_id == EXPORT_BI || bi_id == UNSET_BI || bi_id == ENV_BI)
		return (run_builtin (bi_id, ppl, false));
	return (CONTINUE_PROC);
}
