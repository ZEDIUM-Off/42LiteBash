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

t_uint	echo_builtins(t_str cmd);
t_uint	pwd_builtins(void);
t_uint	cd_builtins(t_str path);

#endif