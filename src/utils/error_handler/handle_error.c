/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 14:22:29 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	syntax_err_format(t_str err_var)
{
	t_str	error_msg;

	error_msg = get_error_msg(SYNTAX_ERROR);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, " `", 2);
	write(2, err_var, ft_strlen(err_var));
	write(2, "'", 1);
}

void	bi_error(t_uint error_code, t_str err_var)
{
	if (error_code == EXPORT_NOT_VALID_ID)
	{
		write(2, "export: `", 9);
		write(2, err_var, ft_strlen(err_var));
		write(2, "': ", 3);
	}
	else if (error_code == EXIT_ARG || error_code == EXIT_TOO_ARG)
	{
		write(2, "exit: ", 6);
		if (error_code == EXIT_ARG)
		{
			write(2, err_var, ft_strlen(err_var));
			write(2, ": ", 2);
		}
	}
}

void	print_error(t_uint error_code, t_str err_var)
{
	write(2, "42LiteBash: ", 13);
	if (error_code == SYNTAX_ERROR || error_code == INVALID_META)
		syntax_err_format(err_var);
	if (error_code >= OPEN_FAIL && error_code <= CD_FAIL)
		perror(err_var);
	if (error_code >= EXPORT_NOT_VALID_ID && error_code <= EXIT_TOO_ARG)
		bi_error(error_code, err_var);
	if (error_code >= NO_FILE_DIR && error_code <= IS_DIR)
	{
		write(2, err_var, ft_strlen(err_var));
		write(2, ": ", 2);
	}
	if (error_code != SYNTAX_ERROR && error_code != OPEN_FAIL
		&& error_code != CLOSE_FAIL)
		write(2, get_error_msg(error_code),
			ft_strlen(get_error_msg(error_code)));
	if (!(error_code >= OPEN_FAIL && error_code <= CD_FAIL))
		write(2, "\n", 1);
}

t_uint	handle_error(t_uint error_code, t_str err_var)
{
	set_exit_status(error_code);
	if (error_code > 2)
		print_error(error_code, err_var);
	if (error_code == MALLOC_FAIL || error_code == EXIT_SHELL
		|| error_code == EXIT_ARG)
		return (EXIT_SHELL);
	else if (error_code != CONTINUE_PROC && error_code != EXPORT_NOT_VALID_ID)
		return (STOP_PROC);
	else
		return (CONTINUE_PROC);
}
