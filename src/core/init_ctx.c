/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:16:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/13 16:20:24 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_sh_context(
	t_sh_context *ctx,
	t_str	*argv,
	int argc
)
{
	ctx->status = 0;
	ctx->mode = 0;
	ctx->line = NULL;
	ctx->blocks = NULL;
	ctx->tk = NULL;
	ctx->error_handler = NULL;
	ctx->envp = NULL;
	ctx->argv = argv;
	ctx->argc = argc;
	ctx->lst_paths = NULL;
	ctx->prompt = NULL;
	ctx->line_split = NULL;
	ctx->pwd = NULL;
}

void	set_ctx(t_sh_context *ctx)
{
	g_shx = ctx;
}
