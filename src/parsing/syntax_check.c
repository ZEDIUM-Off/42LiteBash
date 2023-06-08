/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/08 13:00:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_syntax(t_str line)
{
	t_uint	quote_ctr;
	t_uint	db_quote_ctr;
	t_uint	bracket_ctr;
	t_uint	i;
	int		type;

	quote_ctr = 0;
	db_quote_ctr = 0;
	bracket_ctr = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			quote_ctr++;
		else if (line[i] == '"')
			db_quote_ctr++;
		else if (line[i] == '(')
			bracket_ctr++;
		else if (line[i] == ')')
			bracket_ctr--;
		i++;
	}
}
