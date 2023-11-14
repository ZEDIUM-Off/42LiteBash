/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/13 14:49:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	handle_meta(t_uint meta, t_str *splited, t_uint *i)
{
	t_uint	status;

	status = CONTINUE_PROC;
	if (meta == PIPE)
		status = control_pipe(splited, i);
	else if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		status = control_redirection(splited, i);
	else if (meta == INVALID_META)
		return (handle_error(INVALID_META, splited[*i]));
	if (status != CONTINUE_PROC)
		return (handle_error(status, splited[*i]));
	return (CONTINUE_PROC);
}

t_uint	check_syntax(t_str *splited)
{
	t_quote_test	quotes;
	t_uint			i;
	t_uint			j;
	t_uint			status;
	t_uint			meta;

	i = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	while (splited[i])
	{
		meta = get_meta_char(splited[i]);
		status = handle_meta(meta, splited, &i);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		j = 0;
		while (splited[i][j])
			control_quoting(get_meta_char(&splited[i][j++]), &quotes);
		i++;
	}
	if (quotes.s_quote % 2 != 0 || quotes.d_quote % 2 != 0)
		return (handle_error(UNCLOSED_QUOTES, NULL));
	return (CONTINUE_PROC);
}
