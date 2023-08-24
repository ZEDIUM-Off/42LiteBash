/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:25:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/17 12:53:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include <minish.h>

struct	s_file
{
	int		fd;
	bool	is_open;
	t_str	file_name;
};

struct	s_redirect
{
	t_uint	in_type;
	t_uint	out_type;
	t_file	infile;
	t_file	outfile;
};
struct s_process
{
	int			pipefd[2];
	pid_t		pid;
};

struct s_pipeline
{
	t_redirect	redir;
	t_cmd		*cmd;
	t_process	process;
	t_pipeline	*next;
};

struct s_cmd
{
	t_str	*cmd;
	t_chunk	*chunk;
};

struct	s_chunk
{
	t_uint	end;
	t_str	*txt;
	t_uint	type;
	t_uint	start;
	t_block	*blocks;
	t_chunk	*next;
	t_chunk	*under_chunk;
};

int			parse_pipeline(t_block **blocks, t_str *splited);

t_uint		create_ppl(t_pipeline **new, t_uint size, t_str *splited);
t_uint		add_ppl(t_pipeline **pipeline, t_uint size, t_str *splited);
int			parse_pipe(t_pipeline **ppl, t_str *splited, t_uint size);

#endif /* PIPELINE_H */