/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:21:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/09 13:27:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <minish.h>

struct s_sh_context {
	t_garbage_collector	*gc;
	t_uint				status;
	t_uint				mode;
	t_str				line;
	t_pipeline			*pipeline;
	t_tracker			*tk;
	t_error_handler		*error_handler;
	t_str				*envp;
	t_str				*argv;
	int					argc;
	t_list				*lst_paths;
	t_str				prompt;
	t_str				*history;
	t_str				pwd;
};

void	set_ctx(t_sh_context *ctx);
void	init_sh_context(
			t_sh_context *ctx,
			t_str *envp,
			t_str	*argv,
			int argc
			);


#endif
