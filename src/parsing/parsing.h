/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/01 12:34:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <minish.h>

struct s_block
{
	t_sh_context	*shx;
	t_pipeline		*ppl;
	t_block			*next;
	t_uint			block_end;
	t_uint			bool_to_next;
	bool			exec_result;
};

int			split_line(t_sh_context *shx, t_str **line_split, t_str line);
void		free_split_line(t_sh_context *shx, t_str **line_split);
int			pars_line(t_sh_context *shx, t_block **out, t_str *splited);
void		skip_to_space(t_str str, t_uint *i);

t_uint		get_meta_char(char *c);
void		cmd_expand(t_sh_context *shx, t_cmd **cmd);

void		make_env(t_sh_context *shx, t_uint env_var_name);
t_str		inc_shlvl(void *data);
t_str		*split_parser(t_sh_context *shx, t_str line);

t_list		*get_path(t_sh_context *shx, char **env);
t_list		*add_env_to_lst(t_sh_context *shx, char **envp);
t_list		*add_paths_to_lst(t_sh_context *shx, char **paths);
t_list		*add_env_to_lst_export(t_sh_context *shx, char **envp);

void		swap_nodes(t_list *current_node, t_list *next_node);
void		sort_env_export(t_sh_context *shx);

t_file		new_file(t_str name);

void		check_env(t_sh_context *shx);

#endif