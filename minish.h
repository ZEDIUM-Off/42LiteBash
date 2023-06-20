/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:28:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/20 14:55:32 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H


/**
	===AUTHORIZED FUNCTIONS===
	readline, rl_clear_history, rl_on_new_line,
	rl_replace_line, rl_redisplay, add_history,
	printf, malloc, free, write, access, open, read,
	close, fork, wait, waitpid, wait3, wait4, signal,
	sigaction, sigemptyset, sigaddset, kill, exit,
	getcwd, chdir, stat, lstat, fstat, unlink, execve,
	dup, dup2, pipe, opendir, readdir, closedir,
	strerror, perror, isatty, ttyname, ttyslot, ioctl,
	getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
	tgetnum, tgetstr, tgoto, tputs
	**/
# include <stdio.h>      // printf
# include <stdlib.h>     // malloc, free, exit, getenv
# include <unistd.h>     // access, open, read, close, fork, chdir, getcwd, execve, dup, dup2, pipe, isatty, ttyname, ttyslot, unlink
# include <sys/wait.h>   // wait, waitpid, wait3, wait4
# include <signal.h>     // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/stat.h>   // stat, lstat, fstat
# include <dirent.h>     // opendir, readdir, closedir
# include <string.h>     // strerror
# include <errno.h>      // perror
# include <termios.h>    // tcsetattr, tcgetattr
# include <term.h>       // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <sys/ioctl.h>  // ioctl
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <readline/history.h>
# include <stdbool.h>    // bool
# include <fcntl.h>      // O_RDONLY...

# include "src/utils/Libft/headers/libft.h"
# include "src/types/types.h"
# include "src/types/enums.h"
# include "src/core/core.h"
# include "src/parsing/list/list.h"
# include "src/parsing/parsing.h"
# include "src/parsing/pipeline/pipeline.h"
# include "src/parsing/fill_struct/fill_struct.h"
# include "src/parsing/syntax/syntax.h"
# include "src/utils/utils.h"

extern t_sh_context	*g_shx;

void	prompt(char **env);

#endif