/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/18 10:55:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	skip_until_insert(t_str str, t_uint *i)
{
	while (str[*i] && str[*i] != '"')
		*i += 1;
	if (str[*i])
		*i += 1;
	while (str[*i] && str[*i] != '"')
		*i += 1;
}

t_uint	build_var(t_sh_context *shx, t_export *to_export, t_str current)
{
	t_str	tmp;
	t_uint	i;

	if (current && current[ft_strlen(to_export->name)] == '=')
	{
		i = 0;
		skip_until_insert(current, &i);
		to_export->builded = ft_strinstert(shx, current, to_export->value, i);
		if (!to_export->builded)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	else
	{
		tmp = ft_strjoin(shx, to_export->name, "=");
		tmp = ft_strfjoin(shx, tmp, to_export->value);
		to_export->builded = ft_strdup(shx, tmp);
		if (!to_export->builded)
			return (shx->gc->free(shx, tmp), handle_error(MALLOC_FAIL, NULL));
		shx->gc->free(shx, tmp);
	}
	return (CONTINUE_PROC);
}

int	env_get_index(t_list **env, t_str name)
{
	t_list	*tmp;
	t_uint	i;

	if (!*env || !name)
		return (-1);
	i = 0;
	tmp = *env;
	while (tmp && tmp->data)
	{
		if (ft_strnstr((t_str)tmp->data, name, ft_strlen(name))
			&& (((t_str)tmp->data)[ft_strlen(name)] == '='
			|| !(((t_str)tmp->data)[ft_strlen(name)])))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	init_export(t_sh_context *shx, t_export *to_export)
{
	if (to_export->name)
		gc_free(shx, to_export->name);
	to_export->name = NULL;
	if (to_export->builded)
		gc_free(shx, to_export->builded);
	to_export->builded = NULL;
	if (to_export->value)
		gc_free(shx, to_export->value);
	to_export->value = NULL;
	to_export->type = NONE;
}

t_uint	check_var(t_sh_context *shx, t_str var, t_export *to_export)
{
	t_uint	i;

	if (!var)
		return (handle_error(EXPORT_NOT_VALID_ID, var));
	if (!ft_isalpha(var[0]) && var[0] != '_')
		return (handle_error(EXPORT_NOT_VALID_ID, var));
	i = 1;
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (handle_error(EXPORT_NOT_VALID_ID, var));
		i++;
	}
	to_export->name = ft_strdup(shx, var);
	return (CONTINUE_PROC);
}
