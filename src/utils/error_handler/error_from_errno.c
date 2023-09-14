/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_from_errno.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 20:10:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	open_error(int errnum, t_str filename)
{
	write(2, "minish: ", 8);
	write(2, filename, ft_strlen(filename));
	perror("");
	if (errnum == ENOMEM)
		return (EXIT_SHELL);
	return (CONTINUE_PROC);
}
