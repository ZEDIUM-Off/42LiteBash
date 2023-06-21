/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/21 12:00:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	set_redir(t_pipeline **ppl, t_uint meta, t_str filename)
{
	if (meta == APPEND_REDIRECT || meta == OUT_REDIRECT)
	{
		if ((*ppl)->redir.out_type != NONE)
			return (IMPLICIT_REDIRECT);
		(*ppl)->redir.out_type = meta;
		(*ppl)->redir.outfile = new_file(filename);
	}
	if (meta == IN_REDIRECT || meta == HERE_DOC)
	{
		if ((*ppl)->redir.in_type != NONE)
			return (IMPLICIT_REDIRECT);
		(*ppl)->redir.in_type = meta;
		if (meta == IN_REDIRECT)
			(*ppl)->redir.infile = new_file(filename);
	}
	return (0);
}

int	extract_redirect(
	t_pipeline **ppl, t_str **cmd_no_redir, t_str *splited, t_uint size)
{
	t_uint		meta;
	t_uint		nb_parts;
	t_uint		i;

	nb_parts = 0;
	i = 0;
	while (i < size)
	{
		meta = get_meta_char(&splited[i][0]);
		if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		{
			if (set_redir(ppl, meta, splited[i]) != 0)
				return (IMPLICIT_REDIRECT);
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
	t_uint	i;
	t_uint	status;

	cmd_no_redir = (t_str *)g_shx->gc->malloc(sizeof(t_str)
			* (size + 1), false);
	if (!cmd_no_redir)
		return (MALLOC_FAIL);
	status = extract_redirect(ppl, &cmd_no_redir, splited, size);
	if (status != 0)
		return (status);
	i = 0;
	while (cmd_no_redir[i])
	{
		printf("cmd no redir %d: %s\n", i, cmd_no_redir[i]);
		i++;
	}
	status = new_cmd(&((*ppl)->cmd), cmd_no_redir);
	if (status != 0)
		return (status);
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
		while (splited[i] && i < (*blocks)->block_end)
		{
			if (get_meta_char(&splited[i][0]) == PIPE)
			{
				status = add_ppl(&(*blocks)->ppl, i - start, &splited[start]);
				if (status != 0)
					return (status);
				start = i + 1;
			}
			i++;
		}
		status = add_ppl(&(*blocks)->ppl, i - start, &splited[start]);
		if (status != 0)
			return (status);
		if (i == (*blocks)->block_end)
			start = ++i;
		*blocks = (*blocks)->next;
	}
	*blocks = top;
	return (0);
}
