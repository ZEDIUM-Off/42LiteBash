/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/15 17:36:44 by bfaure           ###   ########lyon.fr   */
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
int			pars_line(t_block **out, t_str *splited);
void		skip_to_space(t_str str, t_uint *i);

t_uint		get_meta_char(char *c);
void		cmd_expand(t_cmd **cmd);

void		make_env(t_uint env_var_name);
t_str		inc_shlvl(void *data);
t_str		*split_parser(t_str line);

t_list		*get_path(char **env);
t_list		*add_env_to_lst(char **envp);
t_list		*add_paths_to_lst(char **paths);

t_file		new_file(t_str name);

void		check_env(void);

#endif