/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/18 10:55:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	parse_pipe(
		t_sh_context *shx, t_pipeline **ppl, t_str *splited, t_uint size)
{
	t_str	*cmd_no_redir;
	t_uint	status;

	cmd_no_redir = (t_str *)shx->gc->malloc(shx, sizeof(t_str)
			* (size + 1), false);
	if (!cmd_no_redir)
		return (handle_error(MALLOC_FAIL, NULL));
	status = extract_redirect(ppl, &cmd_no_redir, splited, size);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = parse_export(shx, cmd_no_redir);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = new_cmd(shx, &((*ppl)->cmd), cmd_no_redir);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	process_block(
		t_sh_context *shx, t_block **blocks, t_str *splited)
{
	t_uint	status;
	t_uint	start;
	t_uint	i;

	i = 0;
	start = i;
	while (splited[i] && i < (*blocks)->block_end)
	{
		if (get_meta_char(&splited[i][0]) == PIPE)
		{
			status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			start = i + 1;
		}
		(i)++;
	}
	status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	parse_pipeline(t_sh_context *shx, t_block **blocks, t_str *splited)
{
	t_uint	status;

	status = process_block(shx, blocks, splited);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
