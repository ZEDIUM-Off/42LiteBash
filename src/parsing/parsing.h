/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/13 14:33:06 by bfaure           ###   ########lyon.fr   */
=======
/*   Updated: 2023/06/13 11:46:10 by  mchenava        ###   ########.fr       */
>>>>>>> 4956b9e1e5b508b64b11398eb9b8c3b09a889959
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
	t_uint		bool_to_next;
	t_block		*next;
};

struct	s_file
{
	t_str	file_name;
	int		fd;
	bool	is_open;
};

int			bracket_mode(void);
t_uint		get_meta_char(char *c);
int			ft_read(t_str line_read);
int			split_line(void);
int			double_quote_mode(t_str line_read, t_p_data *p_data);
int			simple_quote_mode(t_str line_read, t_p_data *p_data);
int			check_double_quote_mode(t_str line_read, t_p_data *p_data);
int			check_simple_quote_mode(t_str line_read, t_p_data *p_data);

t_list		*get_path(char **env);
t_list		*add_env_to_lst(char **envp);
t_list		*add_paths_to_lst(char **paths);
t_str		*split_parser(void);

#endif