/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/14 09:54:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*add_env_to_lst(char **envp)
{
	t_list	*lst_env;
	int		i;

	i = -1;
	trace("add_env_to_lst", "every things is in the name", PARSE);
	lst_env = lst_create(envp[0]);
	while (envp[++i])
	{
		lst_add_back(&lst_env, envp[i]);
	}
	log_action();
	return (lst_env);
}
