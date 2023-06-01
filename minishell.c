#include <minish.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_sh_context	ctx;
	t_garbage_collector	gc;
	init_sh_context(&ctx);
	set_ctx(&ctx);
	printf("g_shx->status: %d\n", g_shx->status);
	gc_init(&gc);
	set_garbage_collector(&gc);
	trace("main", "start", 0);
	return (0);
}