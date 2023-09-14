/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 23:33:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	exit_shell(t_sh_context *shx, t_uint error_code, char *msg)
{
	printf("MINISHELL %d : %s\n", error_code, msg);
	gc_free_all(shx);
	exit(error_code);
}
