/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:35:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/28 14:57:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include <minish.h>

struct s_syntax_checker
{
	t_uint	cursor;
	t_uint	quote_ctr;
	t_uint	db_quote_ctr;
	t_uint	parenthesis_ctr;
};

t_uint	check_syntax(t_str line_read);
t_uint	control_quoting(char *c, t_syntax_checker *syx);
t_uint	control_redirection(char *c, t_syntax_checker *syx);
t_uint	control_pipe(char *c, t_syntax_checker *syx);
// t_uint	check_splited(t_str **splited);

#endif