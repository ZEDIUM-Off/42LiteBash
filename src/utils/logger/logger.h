/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:32:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <minish.h>

void	log_action(t_sh_context *shx);
void	log_struct(t_sh_context *shx);
void	log_blocks(t_block **blocks, t_uint lvl);
void	log_chunk(t_chunk **chunk, t_uint lvl);

#endif