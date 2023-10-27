/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:22:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/27 11:40:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <minish.h>

# define MALLOC_FAIL_MSG "Echec de l'allocation mémoire"
# define PIPE_FAIL_MSG "Echec de la création du pipe"
# define FORK_FAIL_MSG "Echec du fork"
# define EXECVE_FAIL_MSG "Echec de l'exécution de la commande"
# define WAITPID_FAIL_MSG "Echec de waitpid"
# define PROC_NOT_TERMINATED_MSG "Processus non terminé"
# define NULL_DATA_MSG "Données nulles"
# define SYNTAX_ERROR_MSG "syntax error near unexpected token"
# define NO_FILE_DIR_MSG "Fichier ou répertoire non trouvé"
# define CMD_NOT_FOUND_MSG "command not found"
# define CLOSE_FAIL_MSG "Echec de la fermeture du fd"
# define DUP_FAIL_MSG "Echec de la duplication du fd"
# define INVALID_META_MSG "syntax error near invalid token"
# define UNCLOSED_QUOTES_MSG "unclosed quotes"
# define EXPORT_NOT_VALID_ID_MSG "not a valid identifier"
# define EXIT_ARG_MSG "numeric argument required"
# define EXIT_TOO_ARG_MSG "too many arguments"
# define IS_DIR_MSG "Is a directory"
# define NO_ERROR_MSG "\0"

struct	s_error
{
	t_error	*next;
	t_uint	error_code;
	char	*msg;
	t_str	func;
	void	*var;
};

void	exit_shell(t_sh_context *shx);
t_uint	handle_error(t_uint error_code, t_str err_var);
t_str	get_error_msg(t_uint error_code);
t_uint	open_error(int errnum, t_str filename);
void	set_exit_status(t_uint	error_code);

#endif