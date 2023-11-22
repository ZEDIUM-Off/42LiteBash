/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:44:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/22 16:33:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	hd_check_expand(t_sh_context *shx, t_str *to_check)
{
	t_uint			j;
	t_str			tmp;

	j = 0;
	tmp = NULL;
	while ((*to_check)[j])
	{
		if (get_meta_char(&(*to_check)[j]) == DOLLAR_Q)
		{
			tmp = ft_strnjoin(shx, tmp, ft_itoa(shx, g_exit_status),
					ft_strlen(ft_itoa(shx, g_exit_status)));
			j += 2;
		}
		else if (get_meta_char(&(*to_check)[j]) == DOLLAR
			&& (*to_check)[j + 1] && (*to_check)[j + 1] != ' '
			&& (*to_check)[j + 1] != '\t'
			&& (*to_check)[j + 1] != '\'' && (*to_check)[j + 1] != '\"')
			extract_and_expand(shx, to_check, &tmp, &j);
		else if ((*to_check)[j])
			tmp = ft_strnjoin(shx, tmp, &(*to_check)[j++], 1);
	}
	if (tmp)
		*to_check = ft_strdup(shx, tmp);
	return (CONTINUE_PROC);
}

t_uint	hd_test_exp(t_sh_context *shx, bool *expend, t_str *delimiter)
{
	t_str	tmp;
	t_uint	status;

	if (ft_strcspn(*delimiter, "'") != ft_strlen(*delimiter))
		*expend = false;
	if (ft_strcspn(*delimiter, "\"") != ft_strlen(*delimiter))
		*expend = false;
	*expend = true;
	status = extract_quotes(shx, *delimiter, &tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	*delimiter = ft_strdup(shx, tmp);
	if (!*delimiter)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	make_content(t_sh_context *shx, t_str *content, t_str line, bool expend)
{
	t_uint	status;

	if (expend)
	{
		status = hd_check_expand(shx, &line);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (line[0] == '\0')
		*content = ft_strfjoin(shx, *content, "\n");
	else
		*content = ft_strfjoin(shx, *content, line);
	gc_free(shx, line);
	*content = ft_strfjoin(shx, *content, "\n");
	if (!*content)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	here_doc(t_sh_context *shx, t_str *content, t_str delimiter)
{
	t_str	line;
	t_uint	status;
	bool	expend;

	signal(SIGINT, hd_sig);
	status = hd_test_exp(shx, &expend, &delimiter);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (*content)
		gc_free(shx, *content);
	while (1)
	{
		line = readline("> ");
		if (!line)
			return (handle_error(STOP_PROC, NULL));
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& strlen(line) == strlen(delimiter))
			return (free(line), CONTINUE_PROC);
		status = make_content(shx, content, line, expend);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
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
	gc_free((*ppl)->shx, (*ppl)->redir.here_doc_txt);
	(*ppl)->redir.here_doc_txt = NULL;
	(*ppl)->redir.infile.fd = fd;
	status = close_fd(fd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
