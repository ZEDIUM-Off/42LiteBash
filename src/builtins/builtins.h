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

t_uint	echo_builtins(t_sh_context *shx, t_str cmd);
t_uint	pwd_builtins(t_sh_context *shx);
t_uint	cd_builtins(t_sh_context *shx, t_str path);
t_uint	run_builtin(t_uint	bi_id, t_pipeline **ppl);
t_uint	export_cmd(t_cmd **_cmd);
t_uint	unset_cmd(t_cmd **_cmd);
t_str	get_pwd(void);

#endif