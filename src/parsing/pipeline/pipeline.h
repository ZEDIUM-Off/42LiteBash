/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:25:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 13:56:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include <minish.h>

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

struct	s_redirect
{
	t_uint	in_type;
	t_uint	out_type;
	t_file	infile;
	t_file	outfile;
};

#endif /* PIPELINE_H */