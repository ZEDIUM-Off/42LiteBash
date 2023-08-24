/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:43:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/24 12:10:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl)
{
	t_uint	status;

	status = -1;
	if (bi_id == ECHO_BI)
		status = exec_echo(&(*ppl)->cmd);
	else if (bi_id == PWD_BI)
		status = pwd_builtins();
	else if (bi_id == CD_BI)
		status = cd_builtins((*ppl)->cmd->cmd[1]);
	else if (bi_id == EXPORT_BI)
		status = export_cmd(&(*ppl)->cmd);
	else if (bi_id == UNSET_BI)
		status = unset_cmd(&(*ppl)->cmd);
	else if (bi_id == ENV_BI)
		lst_print(&g_shx->envp, "lst envp %u %s\n");
	else if (bi_id == EXIT_BI)
		exit_shell(420, "You say it, you assume it\n");
	return (status);
}
