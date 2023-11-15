/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 11:29:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	rep_char(int count, char c)
{
	char	*str;

	str = malloc(count + 1);
	ft_memset(str, c, count);
	str[count] = '\0';
	return (str);
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
