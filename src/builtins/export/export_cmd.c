/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:12:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/04 10:12:08 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	get_to_export(t_sh_context *shx, t_str cmd, t_export *to_export)
{
	t_uint	i;
	t_uint	status;

	i = 0;
	while (cmd[i] && get_meta_char(&cmd[i]) != EQUAL
		&& get_meta_char(&cmd[i]) != PLUS_EQUAL)
		to_export->name = ft_strnjoin(shx, to_export->name, &cmd[i++], 1);
	status = check_var(shx, to_export->name, to_export);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (cmd[i] && get_meta_char(&cmd[i]) == EQUAL)
	{
		i++;
		to_export->type = EQUAL;
	}
	else if (cmd[i] && get_meta_char(&cmd[i]) == PLUS_EQUAL)
	{
		to_export->type = PLUS_EQUAL;
		i += 2;
	}
	status = extract_quotes(shx, &cmd[i], &to_export->value);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	export_w_args(t_cmd **_cmd)
{
	t_export	to_export;
	t_uint		i;
	t_uint		status;

	i = 1;
	while ((*_cmd)->cmd[i])
	{
		init_export((*_cmd)->shx, &to_export);
		status = get_to_export((*_cmd)->shx, (*_cmd)->cmd[i], &to_export);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = export((*_cmd)->shx, &to_export);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		i++;
	}
	return (CONTINUE_PROC);
}

void	print_export(t_sh_context *shx)
{
	t_list	*tmp;

	tmp = lstcpy(shx, shx->env);
	sort_str_list(&tmp);
	lst_print(&tmp, "declare -x %s\n");
	lst_clear(shx, &tmp);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	if (!(*_cmd)->cmd[1])
		print_export((*_cmd)->shx);
	else
		return (export_w_args(_cmd));
	return (CONTINUE_PROC);
}
