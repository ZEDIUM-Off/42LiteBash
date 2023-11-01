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

t_uint	build_var(t_sh_context *shx, t_export *to_export, t_str current)
{
	t_str	tmp;
	t_uint	i;

	if (current)
	{
		i = 0;
		while (current[i] && current[i] != '"')
			i++;
		i++;
		while (current[i] && current[i] != '"')
			i++;
		to_export->builded = ft_strinstert(shx, current, to_export->value, i);
		if (!to_export->builded)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	else
	{
		tmp = ft_strjoin(shx, to_export->name, "=\"");
		tmp = ft_strfjoin(shx, tmp, to_export->value);
		tmp = ft_strfjoin(shx, tmp, "\"");
		to_export->builded = ft_strdup(shx, tmp);
		if (!to_export->builded)
			return (shx->gc->free(shx, tmp), handle_error(MALLOC_FAIL, NULL));
		shx->gc->free(shx, tmp);
	}
	return (CONTINUE_PROC);
}

int	env_get_index(t_sh_context *shx, t_list **env, t_str name)
{
	t_str	tmp;
	int		ind1;
	int		ind2;

	tmp = NULL;
	printf("env get index name = %s\n", name);
	ind1 = lst_get_index(env, name);
	tmp = ft_strjoin(shx, name, "=");
	printf ("tmp = %s\n", tmp);
	ind2 = lst_get_index(env, tmp);
	shx->gc->free(shx, tmp);
	if (ind1 == ind2)
		return (ind1);
	if (ind1 != -1)
		return (ind1);
	else if (ind2 != -1)
		return (ind2);
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
