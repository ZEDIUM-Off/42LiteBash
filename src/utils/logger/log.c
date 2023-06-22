/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/22 14:27:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	log_action(void)
{
	t_tracker			*tk;
	t_garbage_collector	*gc;

	tk = g_shx->tk;
	gc = g_shx->gc;
	printf("============== loging step %d: %s ==================\n", tk->step_nb, tk->step_name);
	printf("step type: %d\n", tk->step_type);
	printf("current function: [%s]\n", tk->current_func);
	printf("nb of pointers: %d\n", gc->nb_ptrs);
	printf("last pointer allocated : %p, size: %d, allocated in func: %s at step : %d\n", gc->ptrs->ptr, gc->ptrs->size, gc->ptrs->allocated_in.current_func, gc->ptrs->allocated_in.step_nb);
	printf("====================================================\n\n");
}

void log_struct(void)
{
	t_block *blocks;
	t_pipeline *ppl;
	t_uint 	b_ctr;
	t_uint	p_ctr;
	t_cmd 	*cmd;
	t_chunk *chunk;
	t_redirect *redir;
	t_uint i;
	blocks = g_shx->blocks;
	printf("<<<<<<<<<<<<<<<< loging struct >>>>>>>>>>>>>>>>\n");
	b_ctr = 1;
	while (blocks)
	{
		printf("└──block %-5d:\n", b_ctr++);
		ppl = blocks->ppl;
		p_ctr = 1;
		while (ppl)
		{
			printf("\t│\n\t├──pipeline %-5d:\n", p_ctr++);
			cmd = ppl->cmd;
			if (!cmd)
				printf("\t\t│\n\t\t├── cmd: NULL\n");
			printf("\t\t│\n\t\t├── cmd: ");
			i = 0;
			while (cmd->cmd[i])
				printf("%s ", cmd->cmd[i++]);
			printf("\n");
			chunk = cmd->chunk;
			if (chunk)
			{
				printf("\t\t\t│\n\t\t\t├── chunk: ");
				i = 0;
				while (chunk->txt[i])
					printf("%s ", chunk->txt[i++]);
				printf("\n");
			}
			redir = &ppl->redir;
			printf("\t│\n\t├── redir in_type: %d, out_type: %d\n", redir->in_type, redir->out_type);
			printf("\t│\n\t└── files : infile: %s, outfile: %s\n", redir->infile.file_name , redir->outfile.file_name);
			ppl = ppl->next;
		}
		blocks = blocks->next;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}
