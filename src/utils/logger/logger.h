/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/15 13:06:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <minish.h>

void	log_action(void);
void	log_struct(void);
void	log_blocks(t_block **blocks, t_uint lvl);
void	log_chunk(t_chunk **chunk, t_uint lvl);

#endif