/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:16:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 11:29:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_sh_context(
	t_sh_context *ctx,
	t_str	*argv,
	int argc,
	t_str	*envp
)
{
	ctx->line = NULL;
	ctx->blocks = NULL;
	ctx->argv = argv;
	ctx->argc = argc;
	ctx->prompt = NULL;
	ctx->line_split = NULL;
	ctx->pwd = NULL;
	ctx->proc_nb = 0;
	ctx->envp = envp;
	ctx->s_env = NULL;
	ctx->env = NULL;
}
