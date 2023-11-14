/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:44:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/06 14:13:01 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	here_doc(t_sh_context *shx, t_str *content, t_str delimiter)
{
	t_str	line;
	t_uint	status;

	status = CONTINUE_PROC;
	if (*content)
		shx->gc->free(shx, *content);
	while (status == 0)
	{
		line = readline("> ");
		if (!line)
			return (handle_error(STOP_PROC, NULL));
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			return (CONTINUE_PROC);
		}
		*content = ft_strjoin(shx, *content, line);
		shx->gc->free(shx, line);
		if (!*content)
			return (handle_error(MALLOC_FAIL, NULL));
		*content = ft_strjoin(shx, *content, "\n");
		if (!*content)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	handle_here_doc(t_pipeline **ppl)
{
	int		fd;
	t_uint	status;

	(*ppl)->redir.infile.file_name = HERE_DOC_TMP_FILE;
	fd = open(HERE_DOC_TMP_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (handle_error(OPEN_FAIL, (*ppl)->redir.infile.file_name));
	if (write(fd, (*ppl)->redir.here_doc_txt,
			ft_strlen((*ppl)->redir.here_doc_txt)) == -1)
		return (errno);
	free((*ppl)->redir.here_doc_txt);
	(*ppl)->redir.here_doc_txt = NULL;
	(*ppl)->redir.infile.fd = fd;
	status = close_fd(fd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
