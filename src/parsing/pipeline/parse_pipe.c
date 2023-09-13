/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 13:52:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	parse_pipe(t_sh_context *shx, t_pipeline **ppl, t_str *splited, t_uint size)
{
	t_str	*cmd_no_redir;
	t_uint	status;

	cmd_no_redir = (t_str *)shx->gc->malloc(shx, sizeof(t_str)
			* (size + 1), false);
	if (!cmd_no_redir)
		return (MALLOC_FAIL);
	status = extract_redirect(ppl, &cmd_no_redir, splited, size);
	printf("parse_pipe (extract_redir): status = %d\n", status);
	if (status != 0)
		return (status);
	status = new_cmd(shx, &((*ppl)->cmd), cmd_no_redir);
	printf("parse_pipe (new_cmd): status = %d\n", status);
	if (status != 0)
		return (status);
	return (0);
}

int	process_block(
		t_sh_context *shx, t_block **blocks, t_str *splited)
{
	t_uint	status;
	t_uint	start;
	t_uint	i;

	i = 0;
	start = i;
	printf("process_block : start = %d, block_end = %d\n", start, (*blocks)->block_end);
	while (splited[i] && i < (*blocks)->block_end)
	{
		if (get_meta_char(&splited[i][0]) == PIPE)
		{
			printf("process_block : pipe found @ splited[%d] = %s\n", i, splited[i]);
			status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
			if (status != 0)
				return (status);
			start = i + 1;
		}
		(i)++;
	}
	status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
	if (status != 0)
		return (status);
	return (0);
}

int	parse_pipeline(t_sh_context *shx, t_block **blocks, t_str *splited)
{
	t_uint	status;

	printf("parse_pipeline : block = %p\n", *blocks);
	status = process_block(shx, blocks, splited);
	if (status != 0)
		return (status);
	return (0);
}
