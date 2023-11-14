/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:36:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/14 16:11:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	skip_to_space(t_str str, t_uint *i, t_quote_test *quotes)
{
	t_uint	meta;

	meta = get_meta_char(&str[*i]);
	control_quoting(meta, quotes);
	while (str && str[*i] && (
			(str[*i] != ' ' && str[*i] != '\t' && meta != PIPE)
			|| (quotes->s_quote || quotes->d_quote)))
	{
		*i += 1;
		meta = get_meta_char(&str[*i]);
		control_quoting(meta, quotes);
	}
}

void	skip_to_meta(t_str str, t_uint *i)
{
	while (get_meta_char(&str[*i]) != NONE)
		*i += 1;
}

void	skip_chunk(t_str str, t_uint *i, t_quote_test *quotes)
{
	t_uint	meta;

	if (quotes->s_quote)
	{
		meta = get_meta_char(&str[*i]);
		while (str[*i] && meta != SINGLE_QUOTE
			&& meta != DOLLAR_D && meta != DOLLAR_Q && meta != DOLLAR)
		{
			(*i)++;
			meta = get_meta_char(&str[*i]);
		}
		(*i)++;
	}
	else if (quotes->d_quote)
	{
		meta = get_meta_char(&str[*i]);
		while (str[*i] && meta != DOUBLE_QUOTE
			&& meta != DOLLAR_D && meta != DOLLAR_Q && meta != DOLLAR)
		{
			(*i)++;
			meta = get_meta_char(&str[*i]);
		}
		(*i)++;
	}
}

void	skip_to_pipe(t_str str, t_uint *i)
{
	while (str[*i] && str[*i] != '|')
		*i += 1;
}

bool	check_no_space(t_str str, t_uint i, t_quote_test *quotes)
{
	t_uint	meta1;
	t_uint	meta2;

	meta1 = get_meta_char(&str[i]);
	meta2 = get_meta_char(&str[i - 1]);
	return (str[i] && str[i] != ' ' && str[i] != '\t'
		&& !quotes->s_quote && !quotes->d_quote
		&& (meta1 == SINGLE_QUOTE || meta1 == DOUBLE_QUOTE
			|| meta1 == EQUAL || meta1 == PLUS_EQUAL || meta1 == DOLLAR_Q
			|| meta1 == PLUS || meta1 == NONE)
		&& (meta2 == SINGLE_QUOTE || meta2 == DOUBLE_QUOTE
			|| meta2 == EQUAL || meta2 == PLUS_EQUAL || meta2 == DOLLAR_Q
			|| meta2 == PLUS || meta2 == NONE));
}
