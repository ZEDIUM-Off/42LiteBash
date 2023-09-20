// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export_utils.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/18 10:55:51 by  mchenava         #+#    #+#             */
// /*   Updated: 2023/09/18 10:55:51 by  mchenava        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <minish.h>

// t_uint	parse_export(t_str *cmd)
// {
// 	t_uint			i;
// 	t_quote_test	quotes;
// 	t_uint			meta;
// 	t_str			value;
// 	t_str			key;
// 	t_uint		before_space;
// 	t_uint		after_space;

// 	i = 6;
// 	quotes = {false, false};
// 	value = NULL;
// 	key = NULL;
// 	while (cmd[i])
// 	{
// 		meta = get_meta_char(&str[i]);
// 		if (meta == SINGLE_QUOTE)
// 			quotes.s_quote = !quotes.s_quote;
// 		if (meta == DOUBLE_QUOTE)
// 			quotes.d_quote = !quotes.d_quote;
// 		if (quotes->s_quote || quotes->d_quote)
// 			while (str[i] && get_meta_char(&str[i]) == NONE)
// 				i++;
		
// 	}
// 	return (CONTINUE_PROC);
// }

// 		// if (key && (cmd[i] == '(' || cmd[i] == ')'))
// 		// 	return (handle_error(UNEXPECTED_TOKEN, cmd[i]));
// 		// if (key && (cmd[i] == '&' || cmd[i] == ';'))
// 		// 	return (handle_error(NOT_VALID_IDENTIFIER, cmd[i]));