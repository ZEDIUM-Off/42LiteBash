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
t_uint	pwd_builtins(t_sh_context *shx);
t_uint	cd_builtins(t_sh_context *shx, t_cmd *path);
t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl, bool fork);
t_uint	export_cmd(t_cmd **_cmd);
t_uint	export(t_sh_context *shx, t_export *to_export);
void	init_export(t_sh_context *shx, t_export *to_export);
t_uint	unset_cmd(t_cmd **_cmd);
t_str	get_pwd(t_sh_context *shx);
t_uint	check_no_fork_bi(t_uint bi_id, t_pipeline **ppl);
t_uint	check_var(t_sh_context *shx, t_str var, t_export *to_export);
t_uint	build_var(t_sh_context *shx, t_export *to_export, t_str current);
int		env_get_index(t_list **env, t_str name);
t_uint	exit_bi(t_cmd *cmd);
t_uint	print_envs(t_sh_context *shx, t_uint mode, t_list **lst);

#endif