/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:59:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/30 14:59:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static void	make_envx(t_uint env_var_name)
{
	t_str	env_name;

	if (env_var_name == PWD)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		lst_add_back(&g_shx->envx, env_name, 0);
	}
	if (env_var_name == SHLVL)
		lst_add_back(&g_shx->envx, "SHLVL=1", 1);
	if (env_var_name == OLD_PWD)
		lst_add_back(&g_shx->envx, "OLD_PWD=", 2);
	if (env_var_name == ALL)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		lst_add_back(&g_shx->envx, env_name, 0);
		lst_add_back(&g_shx->envx, "SHLVL=2", 1);
		lst_add_back(&g_shx->envx, "OLDPWD=", 2);
	}
	return ;
}

void	check_envx(void)
{
	t_list	*tmp;
	t_uint	pwd;
	t_uint	shlvl;
	t_uint	old_pwd;

	pwd = 0;
	shlvl = 0;
	old_pwd = 0;
	if (!g_shx->envx)
		make_envx(ALL);
	else
	{
		tmp = g_shx->envx;
		while (tmp)
		{
			if (ft_strnstr(tmp->data, "PWD=", 4))
				pwd++;
			else if (ft_strnstr(tmp->data, "SHLVL=", 6))
			{
				lst_remplace(&g_shx->envx, tmp->index, inc_shlvl(tmp->data));
				shlvl++;
			}
			else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
				old_pwd++;
			tmp = tmp->next;
		}
		if (pwd < 1)
			make_envx(PWD);
		if (old_pwd < 1)
			make_envx(OLD_PWD);
		if (shlvl < 1)
			make_envx(SHLVL);
	}
	return ;
}
