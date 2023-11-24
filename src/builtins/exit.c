/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:09:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 13:39:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	exit_status(t_str n)
{
	long long	res;

	res = ft_strtoll(n);
	if ((res == LLONG_MAX || res == LLONG_MIN) && errno == ERANGE)
		return (404);
	res %= 256;
	if (res < 0)
		res += 256;
	return ((t_uint)res);
}

t_uint	check_exit_arg(t_str number)
{
	t_uint	i;

	if (number)
	{
		i = 0;
		while (number[i] && (number[i] == ' '
				|| number[i] == '\t' || number[i] == '\n'))
			i++;
		while (number[i] && number[i] != ' ' && number[i] != '\t'
			&& number[i] != '\n')
		{
			if (!ft_isdigit(number[i]) && number[i] != '-' && number[i] != '+')
				return (handle_error(EXIT_ARG, number));
			i++;
		}
		i = exit_status(number);
		if (i == 404)
			return (handle_error(EXIT_ARG, number));
		g_exit_status = i;
	}
	return (CONTINUE_PROC);
}

t_uint	exit_bi(t_cmd *cmd)
{
	t_uint	status;
	t_str	number;

	printf("exit\n");
	number = NULL;
	if (!cmd->cmd[1])
		return (EXIT_SHELL);
	status = extract_quotes(cmd->shx, cmd->cmd[1], &number);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = check_exit_arg(number);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (cmd->cmd[2])
		return (handle_error(EXIT_TOO_ARG, NULL));
	return (EXIT_SHELL);
}
