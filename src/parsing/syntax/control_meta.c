/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:44:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/02 15:10:45 by  mchenava        ###   ########.fr       */
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

t_uint	control_redirection(t_str *splited, t_uint *i)
{
	t_uint	meta;

	printf ("control redirect\n");
	meta = get_meta_char(splited[*i + 1]);
	if (meta != NONE)
		return (handle_error(SYNTAX_ERROR, splited[*i + 1]));
	if (splited[*i + 1] == NULL)
		return (handle_error(SYNTAX_ERROR, NL));
	return (CONTINUE_PROC);
}

t_uint	control_pipe(t_str *splited, t_uint *i)
{
	t_uint	meta;

	meta = get_meta_char(splited[*i + 1]);
	if (*i == 0 || splited[*i + 1] == NULL || meta == PIPE)
		return (handle_error(SYNTAX_ERROR, splited[*i]));
	return (CONTINUE_PROC);
}
