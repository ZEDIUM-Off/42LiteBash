/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:43:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 13:18:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl)
{
	t_uint			status;
	t_sh_context	*shx;

	shx = (*ppl)->shx;
	status = 0;
	if (bi_id == ECHO_BI)
		status = exec_echo(&(*ppl)->cmd);
	else if (bi_id == PWD_BI)
		status = pwd_builtins();
	else if (bi_id == CD_BI)
		status = cd_builtins(shx, (*ppl)->cmd->cmd[1]);
	else if (bi_id == EXPORT_BI)
		status = export_cmd(&(*ppl)->cmd);
	else if (bi_id == UNSET_BI)
		status = unset_cmd(&(*ppl)->cmd);
	else if (bi_id == ENV_BI)
		lst_print(&shx->envp, "%u %s\n");
	else if (bi_id == EXIT_BI)
		exit_shell(shx, 420, "You say it, you assume it\n");
	exit(status);
	return (status);
}

void	check_exit(t_uint bi_id, t_pipeline **ppl)
{
	t_sh_context	*shx;

	shx = (*ppl)->shx;
	if (bi_id == EXIT_BI)
		exit_shell(shx, 420, "You say it, you assume it\n");
}
