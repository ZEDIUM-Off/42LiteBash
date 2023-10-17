/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/13 12:17:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str g_meta_char[] =
{
	[NONE] = "",
	[IN_REDIRECT] = "<",
	[OUT_REDIRECT] = ">",
	[APPEND_REDIRECT] = ">>",
	[HERE_DOC] = "<<",
	[DOLLAR_Q] = "$?",
	[DOLLAR_D] = "$$",
	[PIPE] = "|",
	[DOLLAR] = "$",
	[SINGLE_QUOTE] = "'",
	[DOUBLE_QUOTE] = "\"",
};

t_str	rep_char(int count, char c)
{
	char	*str;

	str = malloc(count + 1);
	ft_memset(str, c, count);
	str[count] = '\0';
	return (str);
}

void	log_action(t_sh_context *shx)
{
	t_tracker			*tk;
	t_garbage_collector	*gc;

	tk = shx->tk;
	gc = shx->gc;
	printf("============== loging step %d: %s ==================\n", tk->step_nb, tk->step_name);
	printf("step type: %d\n", tk->step_type);
	printf("current function: [%s]\n", tk->current_func);
	printf("nb of pointers: %d\n", gc->nb_ptrs);
	printf("last pointer allocated : %p, size: %d, allocated in func: %s at step : %d\n", gc->ptrs->ptr, gc->ptrs->size, gc->ptrs->allocated_in.current_func, gc->ptrs->allocated_in.step_nb);
	printf("====================================================\n\n");
}

void	log_chunk(t_chunk **chunk, t_uint lvl)
{
	t_chunk	*_chunk;
	t_uint	i;
	t_uint	c_ctr;
	t_str	tabs;

	_chunk = *chunk;
	c_ctr = 1;
	tabs = rep_char(lvl, '\t');
	while (_chunk)
	{
		if (_chunk->next)
			printf("%s│\t\t│\n%s│\t\t├── chunk %-5d: start = %d, end = %d, type = %s\n", tabs, tabs, c_ctr++, _chunk->start, _chunk->end, g_meta_char[_chunk->type]);
		else
			printf("%s│\t\t│\n%s│\t\t└── chunk %-5d:start = %d, end = %d, type = %s\n", tabs, tabs, c_ctr++, _chunk->start, _chunk->end, g_meta_char[_chunk->type]);
		if (_chunk->next)
			printf("%s│\t\t│\t└── chunk txt: ", tabs);
		else
			printf("%s│\t\t\t└── chunk txt: ", tabs);
		i = 0;
		while (_chunk->txt[i])
			printf("[%s],", _chunk->txt[i++]);
		printf("\n");
		if (_chunk->under_chunk)
			log_chunk(&_chunk->under_chunk, lvl + 1);
		if (_chunk->blocks)
			log_blocks(&_chunk->blocks, lvl + 1);
		_chunk = _chunk->next;
	}
}

void	log_cmd(t_cmd **cmd, t_uint lvl)
{
	t_cmd	*_cmd;
	t_uint	i;
	t_str	tabs;

	_cmd = *cmd;
	i = -1;
	tabs = rep_char(lvl, '\t');
	printf("%s│\t│\n%s│\t└── cmd: ", tabs, tabs);
	while (_cmd->cmd[++i])
		printf("%d-[%s],", i, _cmd->cmd[i]);
	printf("\n");
	if (_cmd->chunk)
		log_chunk(&_cmd->chunk, lvl);
}

void	log_redir(t_redirect *redir, t_uint lvl)
{
	t_str	type[5] = {"NONE", "<", ">", ">>", "<<"};
	t_str	tabs;

	tabs = rep_char(lvl, '\t');
	printf("%s│\n\t├── redir in_type: %s, out_type: %s\n", tabs, type[redir->in_type], type[redir->out_type]);
	printf("%s│\n\t└── files : infile: %s, outfile: %s\n", tabs, redir->infile.file_name , redir->outfile.file_name);
}

void	log_ppl(t_pipeline **ppl, t_uint lvl)
{
	t_pipeline	*_ppl;
	t_uint		p_ctr;
	t_str		tabs;

	_ppl = *ppl;
	p_ctr = 1;
	tabs = rep_char(lvl, '\t');
	while (_ppl)
	{
		printf("%s│\n%s├── pipeline %-5d:\n", tabs, tabs, p_ctr++);
		log_cmd(&_ppl->cmd, lvl);
		log_redir(&_ppl->redir, lvl);
		_ppl = _ppl->next;
	}
}

void	log_blocks(t_block **blocks, t_uint lvl)
{
	t_block	*_blocks;
	t_uint	b_ctr;
	t_str	tabs;

	_blocks = *blocks;
	b_ctr = 1;
	tabs = rep_char(lvl, '\t');
	while (_blocks)
	{
		printf("%s└── block %-5d:\n", tabs ,b_ctr++);
		log_ppl(&_blocks->ppl, lvl + 1);
		_blocks = _blocks->next;
	}
}

void log_struct(t_sh_context *shx)
{
	printf("<<<<<<<<<<<<<<<< loging struct >>>>>>>>>>>>>>>>\n");
	log_blocks(&shx->blocks, 0);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}
