/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/14 16:43:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	expand(t_sh_context *shx, t_str to_exp, t_uint end)
{
	t_uint	j;
	t_list	*tmp;

	tmp = shx->env;
	while (tmp)
	{
		j = 0;
		while (((t_str)(tmp->data))[j] != '=')
			j++;
		if (!ft_strncmp(to_exp, tmp->data, j)
			&& end == j)
			return (ft_strdup(shx, &((char *)tmp->data)[++j]));
		tmp = tmp->next;
	}
	return (ft_strdup(shx, ""));
}

void	extract_and_expand(t_sh_context *shx, t_str *to_check,
	t_str *tmp, t_uint *j)
{
	t_uint	start;

	start = ++(*j);
	while ((*to_check)[*j] && get_meta_char(&(*to_check)[*j]) != DOLLAR
		&& get_meta_char(&(*to_check)[*j]) != DOLLAR_Q
			&& get_meta_char(&(*to_check)[*j]) != DOUBLE_QUOTE
			&& get_meta_char(&(*to_check)[*j]) != SINGLE_QUOTE
			&& (*to_check)[*j] != ' ' && (*to_check)[*j] != '\t')
		(*j)++;
	*tmp = ft_strnjoin(shx, *tmp,
			expand(shx, &(*to_check)[start], *j - start),
			ft_strlen(expand(shx, &(*to_check)[start], *j - start)));
}

bool	need_to_exp(t_str *to_check, t_uint *i, t_quote_test *quote)
{
	t_uint	meta;

	meta = get_meta_char(&(*to_check)[*i]);
	control_quoting(meta, quote);
	return (meta == DOLLAR && (*to_check)[*i + 1] && (*to_check)[*i + 1] != ' '
		&& (*to_check)[*i + 1] != '\t' && (*to_check)[*i + 1] != '\''
		&& (*to_check)[*i + 1] != '\"' && !quote->s_quote);
}

t_uint	check_expand(t_sh_context *shx, t_str *to_check)
{
	t_uint			j;
	t_quote_test	quote;
	t_str			tmp;

	j = 0;
	tmp = NULL;
	quote = (t_quote_test){0, 0};
	while ((*to_check)[j])
	{
		if (get_meta_char(&(*to_check)[j]) == DOLLAR_Q && !quote.s_quote)
		{
			tmp = ft_strnjoin(shx, tmp, ft_itoa(g_exit_status),
					ft_strlen(ft_itoa(g_exit_status)));
			j += 2;
		}
		else if (need_to_exp(to_check, &j, &quote))
			extract_and_expand(shx, to_check, &tmp, &j);
		else if ((*to_check)[j])
			tmp = ft_strnjoin(shx, tmp, &(*to_check)[j++], 1);
	}
	*to_check = ft_strdup(shx, tmp);
	if (!*to_check)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	str_expand(t_sh_context *shx, t_str **cmd)
{
	t_uint	i;
	t_uint	status;

	i = 0;
	while ((*cmd)[i])
	{
		status = check_expand(shx, &((*cmd)[i]));
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		i++;
	}
	return (CONTINUE_PROC);
}
