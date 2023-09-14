/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/14 01:57:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	handle_error(t_uint error_code, t_str err_var)
{
	t_str	error_msg;

	error_msg = get_error_msg(error_code);
	if (error_msg && error_code != CONTINUE_PROC)
	{
		printf("(pf)minish[%u]: %s\n", error_code, error_msg);
		write(2, "minish: ", 8);
		if (err_var)
		{
			write(2, err_var, ft_strlen(err_var));
			write(2, ": ", 2);
		}
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	if (error_code == MALLOC_FAIL)
	{
		return (EXIT_SHELL);
	}
	else if (error_code == PIPE_FAIL
		|| error_code == FORK_FAIL
		|| error_code == EXECVE_FAIL)
		return (STOP_PROC);
	else
		return (CONTINUE_PROC);
}
