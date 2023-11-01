/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:09:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/27 11:28:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	exit_status(t_str n, t_uint *si)
{
	long long	res;

	if (*si > 1)
		return (404);
	res = ft_strtoll(n);
	printf ("res = %lld\n", res);
	if ((res == LLONG_MAX || res == LLONG_MIN) && errno == ERANGE)
		return (404);
	res %= 256;
	if (res < 0)
		res += 256;
	return ((t_uint)res);
}

t_uint	join_chunk(t_chunk **chunk, t_str *number, t_uint *si, t_uint *i)
{
	t_uint	j;

	j = 0;
	while ((*chunk)->txt[j])
	{
		if ((*chunk)->txt[j][0] == '-' || (*chunk)->txt[j][0] == '+')
			*si += 1;
		*number = ft_strfjoin((*chunk)->shx, *number, (*chunk)->txt[j]);
		if (!*number)
			return (handle_error(MALLOC_FAIL, NULL));
		j++;
	}
	*i = (*chunk)->end + 1;
	(*chunk) = (*chunk)->next;
	return (CONTINUE_PROC);
}

t_uint	add_number(t_str *number, t_cmd *cmd, t_uint *i)
{
	if (cmd->cmd[*i] && cmd->cmd[*i][0] == '\0')
			*i += 1;
	else if (!cmd->cmd[*i + 1] || cmd->cmd[*i + 1][0] == '\0')
	{
		*number = ft_strfjoin(cmd->shx, *number, cmd->cmd[*i]);
		if (!*number)
			return (handle_error(MALLOC_FAIL, NULL));
		if (!cmd->cmd[*i + 1])
			return (STOP_PROC);
		*i += 1;
	}
	else
		return (handle_error(EXIT_TOO_ARG, NULL));
	return (CONTINUE_PROC);
}

t_uint	full_arg(t_cmd *cmd, t_str *number, t_uint *si)
{
	t_uint	i;
	t_chunk	*chunk;
	t_uint	status;

	i = 1;
	*number = NULL;
	chunk = cmd->chunk;
	status = CONTINUE_PROC;
	while (cmd->cmd[i])
	{
		if (status == STOP_PROC)
			break ;
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (chunk && chunk->start == i + 1)
		{
			status = join_chunk(&chunk, number, si, &i);
			continue ;
		}
		if (cmd->cmd[i] && (cmd->cmd[i][0] == '-' || cmd->cmd[i][0] == '+'))
			*si += 1;
		status = add_number(number, cmd, &i);
	}
	return (CONTINUE_PROC);
}

t_uint	exit_bi(t_cmd *cmd)
{
	t_uint	i;
	t_uint	status;
	t_str	number;
	t_uint	si;

	printf("exit\n");
	si = 0;
	status = full_arg(cmd, &number, &si);
	if (status != CONTINUE_PROC)
		return (status);
	printf("number = %s\n", number);
	if (number)
	{
		i = 0;
		while (number[i])
		{
			if (!ft_isdigit(number[i]) && number[i] != '-' && number[i] != '+')
				return (handle_error(EXIT_ARG, number));
			i++;
		}
		i = exit_status(number, &si);
		if (i == 404)
			return (handle_error(EXIT_ARG, number));
		g_exit_status = i;
	}
	return (EXIT_SHELL);
}
