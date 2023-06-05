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
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free, exit, getenv
#include <unistd.h>     // access, open, read, close, fork, chdir, getcwd, execve, dup, dup2, pipe, isatty, ttyname, ttyslot, unlink
#include <sys/wait.h>   // wait, waitpid, wait3, wait4
#include <signal.h>     // signal, sigaction, sigemptyset, sigaddset, kill
#include <sys/stat.h>   // stat, lstat, fstat
#include <dirent.h>     // opendir, readdir, closedir
#include <string.h>     // strerror
#include <errno.h>      // perror
#include <termios.h>    // tcsetattr, tcgetattr
#include <term.h>       // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <sys/ioctl.h>  // ioctl
#include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history

#include "src/types/types.h"

extern t_sh_context	*g_shx;

#include "src/core/core.h"
#include "src/parsing/parsing.h"
#include "src/utils/utils.h"

void	prompt(void);



#endif