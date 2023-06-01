#include <minish.h>

int	init_sh_context(t_sh_context *ctx)
{
	ctx->status = 0;
	ctx->mode = 0;
	ctx->line = NULL;
	ctx->pipeline = NULL;
	ctx->tk = NULL;
	ctx->error_handler = NULL;
	ctx->env = NULL;
	ctx->path = NULL;
	ctx->prompt = NULL;
	ctx->history = NULL;
	ctx->pwd = NULL;
	return (0);
}