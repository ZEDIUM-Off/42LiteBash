/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:36:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/30 11:13:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	skip_to_space(t_str str, t_uint *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t'
		&& get_meta_char(&str[*i]) == NONE)
		*i += 1;
}

void	skip_space(t_str str, t_uint *i)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		*i += 1;
}

void	skip_to_pipe(t_str str, t_uint *i)
{
	while (str[*i] && str[*i] != '|')
		*i += 1;
}

bool	check_no_space(t_str str, t_uint i, t_quote_test	*quotes)
{
	t_uint	meta1;
	t_uint	meta2;

	meta1 = get_meta_char(&str[i]);
	meta2 = get_meta_char(&str[i - 1]);
	return (str[i] && str[i] != ' ' && str[i] != '\t'
		&& !quotes->s_quote && !quotes->d_quote
		&& (meta1 == SINGLE_QUOTE || meta1 == DOUBLE_QUOTE
			|| meta1 == EQUAL || meta1 == PLUS_EQUAL || meta1 == NONE)
		&& (meta2 == SINGLE_QUOTE || meta2 == DOUBLE_QUOTE
			|| meta2 == EQUAL || meta2 == PLUS_EQUAL || meta2 == NONE));
}
