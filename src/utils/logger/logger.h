/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/13 15:30:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <minish.h>

void	log_action(t_sh_context *shx);
void	log_struct(t_sh_context *shx);
void	log_blocks(t_block **blocks, t_uint lvl);
void	log_redir(t_redirect *redir, t_uint lvl);
void	log_cmd(t_cmd **cmd, t_uint lvl);

#endif