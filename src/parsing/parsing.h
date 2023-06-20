/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 11:36:34 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

struct s_block
{
	t_pipeline	*ppl;
	t_block		*next;
	t_uint		block_end;
	t_uint		bool_to_next;
};



int			split_line(void);
void		free_split_line(void);
int			bracket_mode(void);
int			ft_read(t_str line_read);
int			double_quote_mode(t_str line_read, t_p_data *p_data);
int			simple_quote_mode(t_str line_read, t_p_data *p_data);
int			check_double_quote_mode(t_str line_read, t_p_data *p_data);
int			check_simple_quote_mode(t_str line_read, t_p_data *p_data);
int			pars_line(void);

t_uint		get_meta_char(char *c);

t_str		*split_parser(void);

t_list		*get_path(char **env);
t_list		*add_env_to_lst(char **envp);
t_list		*add_paths_to_lst(char **paths);

t_cmd		*new_cmd(t_uint p_start, t_uint p_end);

t_block		*create_block(t_uint bool_to_next, t_uint split_index);
t_block		*add_block(
				t_block **block, t_uint bool_to_next, t_uint split_index);

t_file	new_file(t_str name);

#endif