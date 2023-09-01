/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:21:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 14:25:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "execution/execution.h"
# include <minish.h>

struct s_sh_context {
	t_garbage_collector	*gc;
	t_uint				status;
	t_uint				mode;
	t_str				line;
	t_block				*blocks;
	t_tracker			*tk;
	t_error_handler		*error_handler;
	t_str				*env;
	t_list				*envp;
	t_list				*envx;
	t_str				*argv;
	int					argc;
	t_list				*lst_paths;
	t_str				prompt;
	t_str				*line_split;
	t_str				pwd;
	t_uint				proc_nb;
};

void	init_sh_context(
			t_sh_context *ctx,
			t_str	*argv,
			int argc,
			t_str	*envp
			);

t_uint	exec_echo(t_cmd **_cmd);

#endif
