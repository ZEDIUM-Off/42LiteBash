/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/14 09:37:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "syntax/syntax.h"
# include <minish.h>

struct s_parsing_data
{
	t_uint	mode;
	void	*data;
	t_uint	pos_cursor;
};

struct s_meta_char
{
	t_uint	end;
	t_str	txt;
	t_uint	type;
	t_uint	start;
};


//A chunk is a portion of cmd between multi meta char
struct	s_chunk
{
	t_uint	end;
	t_str	txt;
	t_uint	type;
	t_uint	start;
	t_chunk	*under_chunk;
};


struct s_block
{
	t_pipeline	*ppl;
	t_block		*next;
	t_file		*infile;
	t_file		*outfile;
	t_uint		bool_to_next;
};


struct s_pipeline
{
	int			in;
	int			out;
	t_cmd		*cmd;
	t_pipeline	*next;
};

struct s_cmd
{
	t_str	cmd;
	t_str	opt;
	t_str	*arg;
	t_chunk	*chunk;
};

struct	s_file
{
	int		fd;
	bool	is_open;
	t_str	file_name;
};

int			split_line(void);
int			bracket_mode(void);
int			ft_read(t_str line_read);
int			double_quote_mode(t_str line_read, t_p_data *p_data);
int			simple_quote_mode(t_str line_read, t_p_data *p_data);
int			check_double_quote_mode(t_str line_read, t_p_data *p_data);
int			check_simple_quote_mode(t_str line_read, t_p_data *p_data);

t_uint		get_meta_char(char *c);

t_str		*split_parser(void);

t_list		*get_path(char **env);
t_list		*add_env_to_lst(char **envp);
t_list		*add_paths_to_lst(char **paths);

#endif