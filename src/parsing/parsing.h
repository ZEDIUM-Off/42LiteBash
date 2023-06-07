/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/07 20:34:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <minish.h>

struct s_parsing_data
{
	t_uint	pos_cursor;
};

int	bracket_mode(void);
int	ft_read(t_str line_read);
int	double_quote_mode(t_str line_read, t_p_data *p_data);
int	simple_quote_mode(t_str line_read, t_p_data *p_data);
int	check_double_quote_mode(t_str line_read, t_p_data *p_data);
int	check_simple_quote_mode(t_str line_read, t_p_data *p_data);

#endif