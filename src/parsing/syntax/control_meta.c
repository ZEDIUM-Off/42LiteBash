/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:44:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/21 11:04:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	control_quoting(char *c, t_syntax_checker *syx)
{
	int	type;

	type = get_meta_char(c);
	if (type == SINGLE_QUOTE)
		syx->quote_ctr++;
	else if (type == DOUBLE_QUOTE)
		syx->db_quote_ctr++;
}

void	control_parenthesis(char *c, t_syntax_checker *syx)
{
	int	type;

	type = get_meta_char(c);
	if (type == O_PARENTHESIS)
		syx->parenthesis_ctr++;
	else if (type == C_PARENTHESIS)
		syx->parenthesis_ctr--;
}

void	control_redirection(char *c, t_syntax_checker *syx)
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

void	control_pipe(char *c, t_syntax_checker *syx)
{
	int		type;
	t_uint	i;

	type = get_meta_char(c);
	if (type == PIPE)
	{
		i = 1;
		while (c[i] && ft_isspace(c[i]))
			i++;
		type = get_meta_char(&c[i]);
		if (type == PIPE && i != 1)
			syx->status = SYNTAX_ERROR;
	}
}

void	control_boolean(char *c, t_syntax_checker *syx)
{
	int		type;
	t_uint	i;

	type = get_meta_char(c);
	if (type == AND || type == OR)
	{
		syx->cursor++;
		type = get_meta_char(c + 1);
		if (type == AND || type == OR)
			syx->status = SYNTAX_ERROR;
		i = 1;
		while (c[i] && ft_isspace(c[i]))
			i++;
		type = get_meta_char(&c[i]);
		if ((type == AND || type == OR) && i != 1)
			syx->status = SYNTAX_ERROR;
	}
}
