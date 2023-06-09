/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/08 16:49:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "syntax/syntax.h"
# include <minish.h>

struct s_parsing_data
{
	t_uint	pos_cursor;
	t_uint	mode;
	void	*data;
};

struct s_meta_char
{
	t_uint	type;
	t_uint	start;
	t_uint	end;
	t_str	txt;
};

struct	s_chunk
{
	t_uint	type;
	t_uint	start;
	t_uint	end;
	t_str	txt;
	t_chunk	*under_chunk;
};

struct s_block
{
	t_file		*infile;
	t_file		*outfile;
	t_pipeline	*ppl;
	t_block		*next;
};

struct	s_file
{
	t_str	file_name;
	int		fd;
	bool	is_open;
};

int	bracket_mode(void);
int	ft_read(t_str line_read);
int	split_line(t_str line_read);
int	double_quote_mode(t_str line_read, t_p_data *p_data);
int	simple_quote_mode(t_str line_read, t_p_data *p_data);
int	check_double_quote_mode(t_str line_read, t_p_data *p_data);
int	check_simple_quote_mode(t_str line_read, t_p_data *p_data);
int	get_meta_char(char *c);

#endif