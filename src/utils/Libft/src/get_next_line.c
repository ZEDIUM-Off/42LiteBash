/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:38:58 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/13 15:01:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/libft.h"

void	clear_buff(char *buff)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strchr_gnl(buff, '\n') + 1;
	while (buff[i] && buff[i + len])
	{
		buff[i] = buff[i + len];
		i++;
	}
	buff[i] = '\0';
}

char	*line_get(char *buff, ssize_t cursor, char *line, int fd)
{
	while (cursor)
	{
		if (buff[0] == 0)
		{
			cursor = read(fd, buff, BUFFER_SIZE);
			if (cursor < 0)
				return (clear_buff(buff), free(line), NULL);
			buff[cursor] = '\0';
		}
		if (ft_strchr_gnl(buff, '\n') > -1 || cursor == 0)
		{
			line = gnl_strnjoin(line, buff, ft_strchr_gnl(buff, '\n'));
			if (!line)
				return (clear_buff(buff), free(line), NULL);
			return (clear_buff(buff), line);
		}
		line = gnl_strnjoin(line, buff, BUFFER_SIZE);
		if (!line)
			return (clear_buff(buff), free(line), NULL);
		buff[0] = '\0';
	}
	return (clear_buff(buff), free(line), NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		cursor;
	char		*line;

	cursor = 1;
	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (clear_buff(buff), free(line), NULL);
	line[0] = '\0';
	line = line_get(buff, cursor, line, fd);
	if (!line)
		return (clear_buff(buff), free(line), NULL);
	if (line[0] == 0)
		return (clear_buff(buff), free(line), NULL);
	else
		return (line);
}
