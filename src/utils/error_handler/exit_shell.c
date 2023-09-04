/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 10:42:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	exit_shell(t_sh_context *shx, t_uint error_code, char *msg)
{
	//trace(shx, "EXIT", "exit minishell", END);
	printf("MINISHELL %d : %s\n", error_code, msg);
	//log_action(shx);
	gc_free_all(shx);
	exit(error_code);
}
