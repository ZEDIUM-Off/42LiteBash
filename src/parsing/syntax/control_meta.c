// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   control_meta.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/06/08 15:44:50 by  mchenava         #+#    #+#             */
// /*   Updated: 2023/09/26 17:00:26 by  mchenava        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <minish.h>

// t_uint	control_quoting(char *c, t_syntax_checker *syx)
// {
// 	int	type;

// 	type = get_meta_char(c);
// 	if (type == SINGLE_QUOTE)
// 		syx->quote_ctr++;
// 	else if (type == DOUBLE_QUOTE)
// 		syx->db_quote_ctr++;
// }

// t_uint	control_redirection(char *c, t_syntax_checker *syx)
// {
// 	int	type;

// 	type = get_meta_char(c);
// 	if (type == APPEND_REDIRECT || type == HERE_DOC)
// 	{
// 		syx->cursor++;
// 		type = get_meta_char(c + 1);
// 		if (type == APPEND_REDIRECT || type == HERE_DOC)
// 			syx->status = SYNTAX_ERROR;
// 	}
// }

// t_uint	control_pipe(t_str current, t_uint *i)
// {
// 	t_uint	status;

// 	t_uint	j;
// 	if (splited[*i + 1] == NULL || splited[*i - 1][0] == '\0')
// 		return (handle_error(PIPE_AFTER_PIPE, NULL));
// }
