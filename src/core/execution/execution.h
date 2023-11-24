/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:04:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 15:16:02 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minish.h>

t_uint	here_doc(t_sh_context *shx, t_str *content, t_str delimiter);
t_uint	exec_bin(t_str *cmd, t_str *envp);
t_uint	exec_cmd(t_block **block, t_pipeline **ppl, int in_fd, int out_fd);
t_uint	processing(t_block **blocks);
t_uint	run_pipeline(t_block **block, t_pipeline **ppl, int in_fd);
t_uint	handle_redir(t_pipeline **ppl, int in_fd, int out_fd);
t_uint	newfd(int oldfd, int newfd);
t_uint	close_fd(int fd);
void	wait_any_proc(t_block **block);
void	update_proc(t_block **block, int status, pid_t pid);
t_uint	wait_all_proc(t_block **block);
void	is_any_proc_ended(t_block **block);
t_uint	handle_here_doc(t_pipeline **ppl);
t_uint	clean_before_exec(t_sh_context *shx, t_pipeline **ppl, t_str	**cmd);
t_str	*ft_dup_tab(t_str *tabl);
void	free_tab_str(char **tabl);

#endif