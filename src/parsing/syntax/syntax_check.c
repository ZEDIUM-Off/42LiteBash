/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/08 16:58:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static void	init_syntax_checker(t_syntax_checker *syx)
{
	syx->cursor = 0;
	syx->quote_ctr = 0;
	syx->db_quote_ctr = 0;
	syx->parenthesis_ctr = 0;
	syx->status = SYNTAX_OK;
}

t_uint	check_syntax(t_str line)
{
	t_syntax_checker	syx;

	init_syntax_checker(&syx);
	while (line[syx.cursor] && syx.status != SYNTAX_ERROR)
	{
		control_quoting(&line[syx.cursor], &syx);
		control_parenthesis(&line[syx.cursor], &syx);
		control_redirection(&line[syx.cursor], &syx);
		control_boolean(&line[syx.cursor], &syx);
		control_pipe(&line[syx.cursor], &syx);
		syx.cursor++;
	}
	if (syx.quote_ctr % 2 != 0
		|| syx.db_quote_ctr % 2 != 0
		|| syx.parenthesis_ctr != 0)
		syx.status = SYNTAX_ERROR;
	return (syx.status);
}
