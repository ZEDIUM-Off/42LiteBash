/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 17:25:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_STRUCT_H
# define FILL_STRUCT_H

# include <minish.h>

int			new_cmd(t_cmd **_cmd, t_str *splited);

t_block		*create_block(t_uint bool_to_next, t_uint split_index);
t_block		*add_block(
				t_block **block, t_uint bool_to_next, t_uint split_index);

t_chunk		*create_chunk(void);
t_chunk		*chunk_size(t_str *splited);
// t_chunk		*chunk_size_bracket(t_str *splited);
// t_chunk		*chunk_size_simple_quote(t_str *splited);
// t_chunk		*chunk_size_double_quote(t_str *splited);
t_chunk		*new_chunk(
				t_uint c_start, t_uint c_end, t_str *splited, t_uint type);

#endif