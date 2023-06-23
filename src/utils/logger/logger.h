/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/23 15:08:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <minish.h>

void	log_action(void);
void 	log_struct(void);
void	log_blocs(t_block **blocks, t_uint lvl);

#endif