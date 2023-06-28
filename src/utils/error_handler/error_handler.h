/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:22:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/28 12:32:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <minish.h>

struct	s_error
{
	t_uint	error_code;
	char	*msg;
	t_str	func;
	void *var;
};

void	exit_shell(t_uint error_code, char *msg);

#endif