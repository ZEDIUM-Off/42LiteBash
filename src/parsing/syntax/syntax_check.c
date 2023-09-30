/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/28 10:12:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_syntax(t_str *splited)
{
	t_uint	i;
	t_uint	status;
	t_uint	meta;
	t_uint	s_quote;
	t_uint	db_quote;

	i = 0;
	s_quote = 0;
	db_quote = 0;
	while (splited[i])
	{
		if (splited[i][0] == '\0')
			i++;
		meta = get_meta_char(splited[i]);
		if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
			control_quoting(meta, &s_quote, &db_quote);
		else if (meta == PIPE)
			status = control_pipe(splited, &i);
		else if (meta >= IN_REDIRECT && meta <= HERE_DOC)
			status = check_redirection(splited, &i);
		else if (meta == INVALID_META)
			return (handle_error(INVALID_META, splited[i]));
		if (status != CONTINUE_PROC)
			return (handle_error(status, splited[i]));
	}
	if (s_quote % 2 != 0 || db_quote % 2 != 0)
		return (handle_error(UNCLOSED_QUOTES, NULL));
	return (CONTINUE_PROC);
}
