/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:16:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 16:37:38 by  mchenava        ###   ########.fr       */
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
	ctx->status = 0;
	ctx->mode = 0;
	ctx->line = NULL;
	ctx->blocks = NULL;
	ctx->tk = NULL;
	ctx->error_handler = NULL;
	ctx->argv = argv;
	ctx->argc = argc;
	ctx->prompt = NULL;
	ctx->line_split = NULL;
	ctx->pwd = NULL;
	ctx->proc_nb = 0;
	ctx->env = envp;
}
