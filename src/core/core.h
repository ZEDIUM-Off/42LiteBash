/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:21:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/31 14:26:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

#include <minish.h>

struct s_sh_context {
	t_uint	status;
	t_uint	mode;
	t_str		line;
	t_pipeline		*pipeline;
	t_garbage_collector	*gc;
	t_tracker	*tk;
	t_error_handler	*error_handler;
	t_str		*env;
	t_str		*path;
	t_str		prompt;
	t_str		*history;
	t_str		pwd;
};

void	set_ctx(t_sh_context *ctx);
int	init_sh_context(t_sh_context *ctx);

#endif
