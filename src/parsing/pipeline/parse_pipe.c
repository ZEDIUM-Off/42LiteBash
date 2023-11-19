/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 17:07:10 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	parse_pipe(
		t_sh_context *shx, t_pipeline **ppl, t_str *splited)
{
	t_uint			status;

	status = new_cmd(shx, &((*ppl)->cmd), splited, (*ppl)->size);
	printf("parse_pipe status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	process_block(t_sh_context *shx, t_block **blocks,
		t_str *splited)
{
	t_uint			status;
	t_uint			start;
	t_uint			i;
	t_uint			meta;

	i = 0;
	start = i;
	while (splited[i] && i < (*blocks)->block_end)
	{
		meta = get_meta_char(&splited[i][0]);
		if (meta == PIPE)
		{
			status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
			printf("process_block status: %d\n", status);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			start = i + 1;
		}
		i++;
	}
	status = add_ppl(shx, &(*blocks)->ppl, i - start, &splited[start]);
	printf("process_block status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	parse_pipeline(t_sh_context *shx, t_block **blocks, t_str *splited)
{
	t_uint			status;

	status = str_expand(shx, &splited);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = process_block(shx, blocks, splited);
	printf("parse_pipeline status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
