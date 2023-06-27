/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/26 15:19:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <minish.h>

struct s_block
{
	t_pipeline	*ppl;
	t_block		*next;
	t_uint		block_end;
	t_uint		bool_to_next;
};

int			split_line(t_str **line_split, t_str line);
void		free_split_line(t_str **line_split);
int			bracket_mode(void);
int			ft_read(t_str line_read);
int			double_quote_mode(t_str line_read, t_p_data *p_data);
int			simple_quote_mode(t_str line_read, t_p_data *p_data);
int			check_double_quote_mode(t_str line_read, t_p_data *p_data);
int			check_simple_quote_mode(t_str line_read, t_p_data *p_data);
int			pars_line(t_block **out, t_str *splited);

t_uint		get_meta_char(char *c);

t_str		*split_parser(t_str line);

t_list		*get_path(char **env);
t_list		*add_env_to_lst(char **envp);
t_list		*add_paths_to_lst(char **paths);

t_file		new_file(t_str name);

#endif