/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:25:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/20 12:38:27 by  mchenava        ###   ########.fr       */
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

struct s_pipeline
{
	t_redirect	redir;
	t_cmd		*cmd;
	t_pipeline	*next;
};

struct s_cmd
{
	t_str	cmd;
	t_str	*opt;
	t_str	*arg;
	t_chunk	*chunk;
};

struct	s_chunk
{
	t_uint	end;
	t_str	txt;
	t_uint	type;
	t_uint	start;
	t_chunk	*under_chunk;
};

void		parse_pipeline(void);

t_pipeline	*create_ppl(t_uint pipe_pos);
t_pipeline	*add_ppl(t_pipeline **pipeline, t_uint pipe_pos);
void	parse_pipe(t_pipeline **ppl, t_uint pipe_pos);

#endif /* PIPELINE_H */