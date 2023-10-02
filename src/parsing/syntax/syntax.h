/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:35:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/02 14:49:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include <minish.h>

# define NL "newline"

struct s_syntax_checker
{
	t_uint	cursor;
	t_uint	quote_ctr;
	t_uint	db_quote_ctr;
	t_uint	parenthesis_ctr;
};

t_uint	check_syntax(t_str *splited);
void	control_quoting(t_uint meta, t_uint *s_quote, t_uint *db_quote);
t_uint	control_redirection(t_str *splited, t_uint *i);
t_uint	control_pipe(t_str *splited, t_uint *i);

#endif