/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:54:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/22 14:46:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	set_in_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	t_uint	status;
	t_str	tmp;

	tmp = NULL;
	(*ppl)->redir.in_type = meta;
	if (meta != HERE_DOC)
	{
		status = extract_quotes((*ppl)->shx, splited[*i], &tmp);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	else
		tmp = ft_strdup((*ppl)->shx, splited[*i]);
	if (tmp == NULL)
		return (handle_error(MALLOC_FAIL, NULL));
	status = new_file((*ppl)->shx,
			&(*ppl)->redir.infile, tmp, (*ppl)->redir.in_type);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (meta != HERE_DOC
		&& get_meta_char(&(*ppl)->redir.infile.file_name[0]) != NONE)
		return (handle_error(NO_FILE_DIR, NULL));
	*i += 1;
	return (CONTINUE_PROC);
}

t_uint	set_out_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	t_uint	status;
	t_str	tmp;

	tmp = NULL;
	(*ppl)->redir.out_type = meta;
	status = extract_quotes((*ppl)->shx, splited[*i], &tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = new_file((*ppl)->shx, &(*ppl)->redir.outfile,
			tmp, (*ppl)->redir.out_type);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (get_meta_char(&(*ppl)->redir.outfile.file_name[0]) != NONE)
		return (handle_error(NO_FILE_DIR, NULL));
	*i += 1;
	return (CONTINUE_PROC);
}

t_uint	set_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	*i += 1;
	if (meta == APPEND_REDIRECT || meta == OUT_REDIRECT)
		return (set_out_redir(ppl, meta, splited, i));
	if (meta == IN_REDIRECT || meta == HERE_DOC)
		return (set_in_redir(ppl, meta, splited, i));
	return (CONTINUE_PROC);
}

t_uint	extract_redirect(
	t_pipeline **ppl, t_str **cmd_no_redir, t_str *splited, t_uint size)
{
	t_uint			meta;
	t_uint			nb_parts;
	t_uint			i;
	t_uint			status;

	nb_parts = 0;
	i = 0;
	status = CONTINUE_PROC;
	while (i < size)
	{
		meta = get_meta_char(&splited[i][0]);
		if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		{
			status = set_redir(ppl, meta, splited, &i);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			continue ;
		}
		(*cmd_no_redir)[nb_parts++] = ft_strdup((*ppl)->shx, splited[i]);
		if (!(*cmd_no_redir)[nb_parts - 1])
			return (handle_error(MALLOC_FAIL, NULL));
		i++;
	}
	return ((*cmd_no_redir)[nb_parts] = NULL, CONTINUE_PROC);
}
