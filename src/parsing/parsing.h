/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:27:07 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/20 17:34:20 by bfaure           ###   ########lyon.fr   */
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

struct s_status_env
{
	t_uint	pwd;
	t_uint	shlvl;
	t_uint	old_pwd;
};

struct s_quote_test
{
	t_uint			s_quote;
	t_uint			d_quote;
};

int			split_line(t_sh_context *shx, t_str **line_split, t_str line);
void		free_split_line(t_sh_context *shx, t_str **line_split);
int			pars_line(t_sh_context *shx, t_block **out, t_str *splited);
void		skip_to_space(t_str str, t_uint *i, t_quote_test *quotes);
void		skip_chunk(t_str str, t_uint *i, t_quote_test *quotes);
void		skip_to_pipe(t_str str, t_uint *i);
void		skip_to_meta(t_str str, t_uint *i);

t_uint		get_meta_char(char *c);
t_uint		str_expand(t_sh_context *shx, t_str **cmd);
t_str		expand(t_sh_context *shx, t_str to_exp, t_uint	end);
t_uint		extract_quotes(t_sh_context *shx, t_str src, t_str *to_build);
t_uint		no_quotes_cmd(t_sh_context *shx, t_cmd **cmd);

t_str		*split_parser(t_sh_context *shx, t_str line);

t_list		*get_path(t_sh_context *shx, char **env);
t_uint		add_env_to_lst(t_sh_context *shx, char **envp);
t_list		*add_paths_to_lst(t_sh_context *shx, char **paths);
t_list		*sort_str_list(t_list **lst);

void		swap_nodes(t_list *current_node, t_list *next_node);

t_uint		new_file(t_sh_context *shx, t_file *file, t_str name, t_uint type);
bool		check_no_space(t_str str, t_uint i, t_quote_test	*quotes);
t_uint		check_env(t_sh_context *shx);
t_str		inc_shlvl(t_sh_context *shx, void *data);
#endif
