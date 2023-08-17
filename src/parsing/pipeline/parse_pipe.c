/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/29 17:10:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	set_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	*i += 1;
	if (meta == APPEND_REDIRECT || meta == OUT_REDIRECT)
	{
		if ((*ppl)->redir.out_type != NONE)
			return (IMPLICIT_REDIRECT);
		(*ppl)->redir.out_type = meta;
		meta = get_meta_char(&splited[*i][0]);
		if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
			(*ppl)->redir.outfile = new_file(splited[++*i++]);
		else
			(*ppl)->redir.outfile = new_file(splited[*i]);
		if (get_meta_char(&(*ppl)->redir.outfile.file_name[0]) != NONE)
			return (NO_FILE_DIR);
	}
	if (meta == IN_REDIRECT || meta == HERE_DOC)
	{
		if ((*ppl)->redir.in_type != NONE)
			return (IMPLICIT_REDIRECT);
		(*ppl)->redir.in_type = meta;
		meta = get_meta_char(&splited[*i][0]);
		if ((meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
			&& (*ppl)->redir.in_type == IN_REDIRECT)
			(*ppl)->redir.infile = new_file(splited[++*i++]);
		else if (meta == IN_REDIRECT)
			(*ppl)->redir.infile = new_file(splited[*i]);
		if (get_meta_char(&(*ppl)->redir.infile.file_name[0]) != NONE)
			return (NO_FILE_DIR);
	}
	return (0);
}

int	extract_redirect(
	t_pipeline **ppl, t_str **cmd_no_redir, t_str *splited, t_uint size)
{
	t_uint		meta;
	t_uint		nb_parts;
	t_uint		i;
	t_uint		status;

	nb_parts = 0;
	i = 0;
	while (i < size)
	{
		meta = get_meta_char(&splited[i][0]);
		if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		{
			status = set_redir(ppl, meta, splited, &i);
			if (status != 0)
				return (status);
			i++;
		}
		else
			(*cmd_no_redir)[nb_parts++] = ft_strdup(splited[i]);
		i++;
	}
	(*cmd_no_redir)[nb_parts] = NULL;
	return (0);
}

int	parse_pipe(t_pipeline **ppl, t_str *splited, t_uint size)
{
	t_str	*cmd_no_redir;
	t_uint	status;

	cmd_no_redir = (t_str *)g_shx->gc->malloc(sizeof(t_str)
			* (size + 1), false);
	if (!cmd_no_redir)
		return (MALLOC_FAIL);
	status = extract_redirect(ppl, &cmd_no_redir, splited, size);
	if (status != 0)
		return (status);
	status = new_cmd(&((*ppl)->cmd), cmd_no_redir);
	if (status != 0)
		return (status);
	return (0);
}

int	process_block(t_block **blocks, t_str *splited, t_uint *i, t_uint *start)
{
	t_uint	status;

	while (splited[*i] && *i < (*blocks)->block_end)
	{
		if (get_meta_char(&splited[*i][0]) == PIPE)
		{
			status = add_ppl(&(*blocks)->ppl, *i - *start, &splited[*start]);
			if (status != 0)
				return (status);
			*start = *i + 1;
		}
		(*i)++;
	}
	status = add_ppl(&(*blocks)->ppl, *i - *start, &splited[*start]);
	if (status != 0)
		return (status);
	if (*i == (*blocks)->block_end)
		*start = ++(*i);
	return (0);
}

int	parse_pipeline(t_block **blocks, t_str *splited)
{
	t_uint	i;
	t_uint	start;
	t_uint	status;
	t_block	*top;

	i = 0;
	top = (t_block *)(*blocks);
	while (*blocks)
	{
		start = i;
		status = process_block(blocks, splited, &i, &start);
		if (status != 0)
			return (status);
		*blocks = (*blocks)->next;
	}
	*blocks = top;
	return (0);
}
