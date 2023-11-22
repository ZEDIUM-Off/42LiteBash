/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/21 17:03:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	ft_write_history(t_sh_context *shx, t_str line)
{
	int		fd;

	fd = open(shx->histfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (handle_error(OPEN_FAIL, shx->histfile));
	write(fd, "\n", 1);
	write(fd, line, ft_strlen(line));
	return (close_fd(fd));
}

t_uint	ft_read_history(t_sh_context *shx)
{
	int		fd;
	t_str	line;

	fd = open(shx->histfile, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (handle_error(OPEN_FAIL, shx->histfile));
	rl_clear_history();
	line = get_next_line(fd);
	while (line)
	{
		line[ft_strcspn(line, "\n")] = '\0';
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	return (close_fd(fd));
}
