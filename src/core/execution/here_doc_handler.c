/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:44:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/07 17:02:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	here_doc(t_sh_context *shx, t_str *content, t_str delimiter)
{
	t_str	line;
	t_uint	status;

	status = 0;
	if (*content)
		free(*content);
	while (status == 0)
	{
		line = readline("> ");
		if (!line)
			return (MALLOC_FAIL);
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			return (0);
		}
		*content = ft_strjoin(shx, *content, line);
		free(line);
		if (!*content)
			return (MALLOC_FAIL);
		*content = ft_strjoin(shx, *content, "\n");
		if (!*content)
			return (MALLOC_FAIL);
	}
	return (0);
}

t_uint	handle_here_doc(t_pipeline **ppl)
{
	int	fd;

	(*ppl)->redir.infile.file_name = HERE_DOC_TMP_FILE;
	fd = open(HERE_DOC_TMP_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (errno);
	if (write(fd, (*ppl)->redir.here_doc_txt,
			ft_strlen((*ppl)->redir.here_doc_txt)) == -1)
		return (errno);
	free((*ppl)->redir.here_doc_txt);
	(*ppl)->redir.here_doc_txt = NULL;
	(*ppl)->redir.infile.fd = fd;
	close(fd);
	return (0);
}
