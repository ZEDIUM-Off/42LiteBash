/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:43:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/26 11:20:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl, bool fork)
{
	t_uint			status;

	status = CONTINUE_PROC;
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
	else if (bi_id == ENV_BI && !fork)
		status = lst_print(&(*ppl)->shx->envp, "%s\n");
	else if (bi_id == EXIT_BI && !fork)
		status = exit_bi((*ppl)->cmd);
	if (fork)
		exit (status);
	return (handle_error(status, NULL));
}

t_uint	check_no_fork_bi(t_uint bi_id, t_pipeline **ppl)
{
	if (bi_id == EXIT_BI
		|| bi_id == EXPORT_BI || bi_id == UNSET_BI || bi_id == ENV_BI)
		return (run_builtin (bi_id, ppl, false));
	return (CONTINUE_PROC);
}
