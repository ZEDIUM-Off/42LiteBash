/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:44:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/28 10:14:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	control_quoting(t_uint meta, t_uint *s_quote, t_uint *db_quote)
{
	if (meta == SINGLE_QUOTE)
		*s_quote += 1;
	else if (meta == DOUBLE_QUOTE)
		*db_quote += 1;
}

t_uint	control_redirection(char *c, t_syntax_checker *syx)
{
	int	type;

	type = get_meta_char(c);
	if (type == APPEND_REDIRECT || type == HERE_DOC)
	{
		syx->cursor++;
		type = get_meta_char(c + 1);
		if (type == APPEND_REDIRECT || type == HERE_DOC)
			syx->status = SYNTAX_ERROR;
	}
}

t_uint	control_pipe(t_str *splited, t_uint *i)
{
	t_uint	status;

	t_uint	j;
	if (splited[*i + 1] == NULL || splited[*i - 1][0] == '\0')
		return (handle_error(PIPE_AFTER_PIPE, NULL));
}
