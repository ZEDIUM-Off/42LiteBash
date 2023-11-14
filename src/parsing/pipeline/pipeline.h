/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:25:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/14 16:45:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include <minish.h>

struct	s_file
{
	int		fd;
	bool	valid;
	bool	is_open;
	t_str	file_name;
};

struct	s_redirect
{
	t_uint			in_type;
	t_uint			out_type;
	t_str			here_doc_txt;
	t_file			infile;
	t_file			outfile;
};
struct s_process
{
	int			pipefd[2];
	pid_t		pid;
	int			status;
};

struct s_pipeline
{
	bool			exec;
	t_uint			size;
	t_sh_context	*shx;
	t_redirect		redir;
	t_cmd			*cmd;
	t_process		process;
	t_pipeline		*next;
};

struct s_cmd
{
	t_sh_context	*shx;
	t_uint			size;
	t_str			*cmd;
};

t_uint		parse_pipeline(t_sh_context *shx, t_block **blocks, t_str *splited);
t_uint		extract_redirect(
				t_pipeline **ppl,
				t_str **cmd_no_redir, t_str *splited, t_uint size);
t_uint		create_ppl(t_sh_context *shx, t_pipeline **new,
				t_uint size, t_str *splited);
t_uint		add_ppl(t_sh_context *shx, t_pipeline **pipeline,
				t_uint size, t_str *splited);
t_uint		parse_pipe(t_sh_context *shx,
				t_pipeline **ppl, t_str *splited);

#endif /* PIPELINE_H */