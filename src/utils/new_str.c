#include <minish.h>

t_str	new_str(t_str str)
{
	t_str	new_str;

	new_str = g_shx->gc->malloc(sizeof(str));
	if (!new_str)
		return (NULL);
	strcpy(new_str, str);
	return (new_str);
}