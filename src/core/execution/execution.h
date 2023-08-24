/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:04:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/24 11:59:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minish.h>

t_uint	handle_chunck(t_chunk **chunk);
t_uint	exec_bin(t_pipeline	**ppl);
t_uint	exec_cmd(t_pipeline **ppl);
t_uint	processing(t_block **blocks);
t_uint	run_pipeline(t_pipeline **ppl, int in_fd);
t_uint	last_process(t_pipeline **ppl, int in_fd);
t_uint	parent_process(t_pipeline **ppl, int in_fd);
t_uint	child_process(t_pipeline **ppl, int in_fd);
t_uint	handle_redir(t_pipeline **ppl, int in_fd);
t_uint	newfd(int oldfd, int newfd);
t_uint	close_fd(int fd);
t_uint	wait_for_proc(void);

#endif