/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:14:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 13:44:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	no_quotes_cmd(t_sh_context *shx, t_cmd **cmd)
{
	t_uint	i;
	t_uint	status;
	t_str	tmp;
	t_uint	offset;

	i = 0;
	offset = 0;
	while ((*cmd)->cmd[i])
	{
		tmp = NULL;
		status = extract_quotes(shx, (*cmd)->cmd[i], &tmp);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (tmp)
		{
			gc_free(shx, (*cmd)->cmd[i - offset]);
			(*cmd)->cmd[i - offset] = ft_strdup(shx, tmp);
			if (!(*cmd)->cmd[i - offset])
				return (handle_error(MALLOC_FAIL, NULL));
		}
		else
			offset++;
		i++;
	}
	return ((*cmd)->cmd[i - offset] = NULL, CONTINUE_PROC);
}

t_uint	extract_quotes(t_sh_context *shx, t_str src, t_str *to_build)
{
	t_uint			meta;
	t_uint			j;

	j = 0;
	while (src[j])
	{
		meta = get_meta_char(&src[j]);
		if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
		{
			j++;
			while (meta != get_meta_char(&src[j]))
			{
				*to_build = ft_strnjoin(shx, *to_build, &src[j], 1);
				j++;
			}
		}
		else
			*to_build = ft_strnjoin(shx, *to_build, &src[j], 1);
		if (src[j])
			j++;
	}
	return (CONTINUE_PROC);
}
