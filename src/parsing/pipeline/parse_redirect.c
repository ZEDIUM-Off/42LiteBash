/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:54:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 15:38:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	set_in_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	t_uint	status;

	printf ("set_in_redir, i = %d\n", *i);
	(*ppl)->redir.in_type = meta;
	meta = get_meta_char(&splited[*i][0]);
	if ((meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE))
		status = new_file(&(*ppl)->redir.infile, splited[++*i++]);
	else
	{
		if ((*ppl)->redir.in_type == HERE_DOC)
			status = here_doc(&(*ppl)->redir.here_doc_txt, splited[*i]);
		else
			status = new_file(&(*ppl)->redir.infile, splited[*i]);
	}
	if (status != 0)
		return (status);
	if (get_meta_char(&(*ppl)->redir.infile.file_name[0]) != NONE)
		return (NO_FILE_DIR);
	printf ("set_in_redir, after i = %d\n", *i);
	return (0);
}

t_uint	set_out_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	t_uint	status;

	(*ppl)->redir.out_type = meta;
	meta = get_meta_char(&splited[*i][0]);
	if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
		status = new_file(&(*ppl)->redir.outfile, splited[++*i++]);
	else
		status = new_file(&(*ppl)->redir.outfile, splited[*i]);
	if (status != 0)
		return (status);
	if (get_meta_char(&(*ppl)->redir.outfile.file_name[0]) != NONE)
		return (NO_FILE_DIR);
	return (0);
}

int	set_redir(t_pipeline **ppl, t_uint meta, t_str *splited, t_uint *i)
{
	*i += 1;
	if (meta == APPEND_REDIRECT || meta == OUT_REDIRECT)
	{
		return (set_out_redir(ppl, meta, splited, i));
	}
	if (meta == IN_REDIRECT || meta == HERE_DOC)
	{
		return (set_in_redir(ppl, meta, splited, i));
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
	printf ("extract_redirect size: %d\n", size);
	while (i < size)
	{
		printf ("splited[%d] = [%s]\n", i, splited[i]);
		meta = get_meta_char(&splited[i][0]);
		if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		{
			printf ("redir -> %u\n", meta);
			status = set_redir(ppl, meta, splited, &i);
			if (status != 0)
				return (status);
			log_redir(&(*ppl)->redir, 0);
		}
		else
			(*cmd_no_redir)[nb_parts++] = ft_strdup(splited[i]);
		i++;
	}
	(*cmd_no_redir)[nb_parts] = NULL;
	return (0);
}