/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:43:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/27 23:43:36 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minish.h>

struct s_export
{
	t_str	name;
	t_str	value;
	t_str	builded;
	t_uint	type;
};

t_uint	exec_echo(t_cmd **_cmd);
t_uint	pwd_builtins(void);
t_uint	cd_builtins(t_sh_context *shx, t_str path);
t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl, bool fork);
t_uint	export_cmd(t_cmd **_cmd);
t_uint	export(t_sh_context *shx, t_export *to_export);
t_uint	unset_cmd(t_cmd **_cmd);
t_str	get_pwd(void);
t_uint	check_no_fork_bi(t_uint bi_id, t_pipeline **ppl);
t_uint	check_var(t_sh_context *shx, t_str var, t_export *to_export);
t_uint	handle_chunk_var(t_chunk **chunk, t_cmd **_cmd,
			t_export *to_export, t_uint *i);
void	init_export(t_sh_context *shx, t_export *to_export);
t_uint	handle_plus_equal(t_cmd **_cmd, t_chunk **chunk,
			t_export *to_export, t_uint *i);
t_uint	handle_var(t_cmd **_cmd, t_chunk **chunk,
			t_export *to_export, t_uint *i);
t_uint	get_value(t_cmd **_cmd, t_chunk **chunk,
			t_export *to_export, t_uint *i);
t_uint	set_var(t_sh_context *shx, t_export *to_export);
t_uint	append_var(t_sh_context *shx, t_export *to_export);
t_uint	build_var(t_sh_context *shx, t_export *to_export, t_str current);
int		env_get_index(t_sh_context *shx, t_list **env, t_str name);
t_uint	exit_bi(t_cmd *cmd);

#endif