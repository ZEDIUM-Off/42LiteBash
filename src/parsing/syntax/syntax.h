/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:35:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/24 15:24:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include <minish.h>

# define NL "newline"

t_uint	check_syntax(t_str *splited);
void	control_quoting(t_uint meta, t_quote_test *quotes);
t_uint	control_redirection(t_str *splited, t_uint *i);
t_uint	control_pipe(t_str *splited, t_uint *i);

#endif