/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:21:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/31 14:26:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// Structure for a command
typedef struct s_command
{
    char **args; // Arguments for the command
    int pipe;    // Indicates if the command should be piped
} t_command;

// Function prototypes
void shell_loop(void);
char *read_line(void);
t_command **parse_line(char *line);
int execute_commands(t_command **commands);

#endif
