/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/23 15:45:26 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	ft_write_history(t_str line)
{
	int	fd;

	fd = open(HIST_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (handle_error(NO_FILE_DIR, NULL));
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	close(fd);
	return (CONTINUE_PROC);
}

t_uint	ft_read_history(void)
{
	int		fd;
	t_str	line;

	fd = open(HIST_FILE, O_RDONLY);
	if (fd == -1)
		return (handle_error(NO_FILE_DIR, NULL));
	line = get_next_line(fd);
	while (line)
	{
		add_history(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (CONTINUE_PROC);
}
