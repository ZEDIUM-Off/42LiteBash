 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:44:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/08 15:46:32 by  mchenava        ###   ########.fr       */
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
	if (type == APPEND_REDIRECT || type == IN_TO_DELIM)
	{
		syx->cursor++;
		type = get_meta_char(c + 1);
		if (type == APPEND_REDIRECT || type == IN_TO_DELIM)
		{
			syx->status = SYNTAX_ERROR;
			printf ("redirection error -> %c, pos = %d\n", c[syx->cursor], syx->cursor);
		}
	}
}

void	control_pipe(char *c, t_syntax_checker *syx)
{
	int		type;
	t_uint	i;

	type = get_meta_char(c);
	i = syx->cursor;
	printf ("current char = %s, %c - %c, i = %d\n", c, *c, c[i], i);
	if (type == PIPE)
	{
		printf ("string : [%s], char is pipe -> [%c], pos = %d\n", c, c[i], i);
		while (c[i] && ft_isspace(c[i]))
			i++;
		printf ("string : [%s], char after space skip [%c], pos = %d\n", c, c[i], i);
		type = get_meta_char(&c[i]);
		if (type == PIPE)
		{
			printf ("pipe error -> %c, pos = %d\n", c[i], i);
			syx->status = SYNTAX_ERROR;
		}
	}
}

void	control_boolean(char *c, t_syntax_checker *syx)
{
	int	type;

	type = get_meta_char(c);
	if (type == AND || type == OR)
	{
		syx->cursor++;
		type = get_meta_char(c + 1);
		if (type == AND || type == OR)
		{
			printf ("bool error -> %c, pos = %d\n", c[syx->cursor], syx->cursor);
			syx->status = SYNTAX_ERROR;
		}
	}
}
