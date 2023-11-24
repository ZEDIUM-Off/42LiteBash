/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:43:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 13:43:37 by  mchenava        ###   ########.fr       */
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
		status = pwd_builtins((*ppl)->shx);
	else if (bi_id == CD_BI && !fork)
		status = cd_builtins((*ppl)->shx, (*ppl)->cmd);
	else if (bi_id == EXPORT_BI && !fork)
		status = export_cmd(&(*ppl)->cmd);
	else if (bi_id == UNSET_BI && !fork)
		status = unset_cmd(&(*ppl)->cmd);
	else if (bi_id == ENV_BI)
		status = print_envs((*ppl)->shx, ENV_BI, &(*ppl)->shx->env);
	else if (bi_id == EXIT_BI && !fork)
		status = exit_bi((*ppl)->cmd);
	return (handle_error(status, NULL));
}

t_uint	check_no_fork_bi(t_uint bi_id, t_pipeline **ppl)
{
	t_uint	status;
	t_str	*cmd_no_redir;

	if (bi_id == EXIT_BI || bi_id == EXPORT_BI || bi_id == CD_BI
		|| bi_id == UNSET_BI)
	{
		if ((*ppl)->next)
			return (CONTINUE_PROC);
		cmd_no_redir = (t_str *)(*ppl)->shx->gc->malloc((*ppl)->shx,
				sizeof(t_str) * ((*ppl)->size + 1), false);
		if (!cmd_no_redir)
			return (handle_error(MALLOC_FAIL, NULL));
		status = extract_redirect(ppl, &cmd_no_redir,
				(*ppl)->cmd->cmd, (*ppl)->cmd->size);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		gc_free((*ppl)->shx, (*ppl)->cmd->cmd);
		(*ppl)->cmd->cmd = cmd_no_redir;
		status = no_quotes_cmd((*ppl)->shx, &(*ppl)->cmd);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		return (run_builtin (bi_id, ppl, false));
	}
	return (CONTINUE_PROC);
}
