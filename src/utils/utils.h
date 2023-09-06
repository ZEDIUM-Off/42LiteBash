/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/06 19:37:45 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tracker/tracker.h"
# include "garbage_collector/garbage.h"
# include "error_handler/error_handler.h"
# include "logger/logger.h"
# include <minish.h>

t_str	new_str(t_sh_context *shx, t_str str);
t_uint	init_shell(
			t_sh_context *shx,
			t_str *envp,
			t_str *argv,
			int argc
			);
void	clean_blocks(t_sh_context *shx, t_block **blocks);
void	clean_ppl(t_sh_context *shx, t_pipeline **ppl);
void	clean_cmd(t_sh_context *shx, t_cmd **cmd);
void	clean_chunk(t_sh_context *shx, t_chunk **chunk);

#endif