/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:20:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/01 12:37:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	check_env(t_sh_context *shx)
{
	t_list	*tmp;
	t_uint	pwd;
	t_uint	shlvl;
	t_uint	old_pwd;

	pwd = 0;
	shlvl = 0;
	old_pwd = 0;
	if (!shx->envp)
		make_env(shx, ALL);
	else
	{
		tmp = shx->envp;
		while (tmp)
		{
			if (ft_strnstr(tmp->data, "PWD=", 4))
				pwd++;
			else if (ft_strnstr(tmp->data, "SHLVL=", 6))
			{
				lst_remplace(shx, &shx->envp, tmp->index, inc_shlvl(tmp->data));
				shlvl++;
			}
			else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
				old_pwd++;
			tmp = tmp->next;
		}
		// printf("pwd = %i, shlvl = %i, old_pwd = %i\n", pwd, shlvl, old_pwd);
		if (pwd < 1)
			make_env(shx, PWD);
		if (old_pwd < 1)
			make_env(shx, OLD_PWD);
		if (shlvl < 1)
			make_env(shx, SHLVL);
	}
	return ;
}

t_str	inc_shlvl(void *data)
{
	int		num_i;
	t_str	num_c;
	t_str	new_shlvl;

	new_shlvl = ft_strdup("SHLVL=");
	data += 6;
	num_i = ft_atoi(data);
	num_i++;
	num_c = ft_itoa(num_i);
	new_shlvl = ft_strfjoin(new_shlvl, num_c);
	return (new_shlvl);
}

void	make_env(t_sh_context *shx, t_uint env_var_name)
{
	t_str	env_name;

	if (env_var_name == PWD)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		lst_add_back(shx, &shx->envp, env_name, 0);
	}
	if (env_var_name == SHLVL)
		lst_add_back(shx, &shx->envp, "SHLVL=1", 1);
	if (env_var_name == OLD_PWD)
		lst_add_back(shx, &shx->envp, "OLD_PWD=", 2);
	if (env_var_name == ALL)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		lst_add_back(shx, &shx->envp, env_name, 0);
		lst_add_back(shx, &shx->envp, "SHLVL=1", 1);
		lst_add_back(shx, &shx->envp, "OLDPWD=", 2);
	}
	return ;
}

// void	check_envp(void)
// {
// 	t_list	*tmp;
// 	t_uint	pwd;
// 	t_uint	shlvl;
// 	t_uint	old_pwd;

// 	pwd = 0;
// 	shlvl = 0;
// 	old_pwd = 0;
// 	if (!g_shx->envp)
// 		make_envp(ALL);
// 	else
// 	{
// 		tmp = g_shx->envp;
// 		while (tmp)
// 		{
// 			if (ft_strnstr(tmp->data, "PWD=", 4))
// 				pwd++;
// 			else if (ft_strnstr(tmp->data, "SHLVL=", 6))
// 			{
// 				lst_remplace(&g_shx->envp, tmp->index, inc_shlvl(tmp->data));
// 				shlvl++;
// 			}
// 			else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
// 				old_pwd++;
// 			tmp = tmp->next;
// 		}
// 		if (pwd < 1)
// 			make_envp(PWD);
// 		if (old_pwd < 1)
// 			make_envp(OLD_PWD);
// 		if (shlvl < 1)
// 			make_envp(SHLVL);
// 	}
// 	return ;
// }

// t_str	inc_shlvl(void *data)
// {
// 	int		num_i;
// 	t_str	num_c;
// 	t_str	new_shlvl;

// 	new_shlvl = ft_strdup("SHLVL=");
// 	data += 6;
// 	num_i = ft_atoi(data);
// 	num_i++;
// 	num_c = ft_itoa(num_i);
// 	new_shlvl = ft_strfjoin(new_shlvl, num_c);
// 	free(num_c);
// 	return (new_shlvl);
// }

