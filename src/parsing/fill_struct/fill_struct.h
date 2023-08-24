/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/24 11:36:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_STRUCT_H
# define FILL_STRUCT_H

# include <minish.h>

t_uint			check_builtins(char *str);
t_uint	new_cmd(t_cmd **_cmd, t_str *splited);

t_uint		create_block(
				t_block **new, t_uint bool_to_next, t_uint split_index);
t_uint		add_block(
				t_block **block, t_uint bool_to_next, t_uint split_index);

t_uint	create_chunk(t_chunk **new, t_uint	chunk_lim[2], t_uint type);
t_uint	chunk_size(t_chunk	**chunk, t_str *splited, t_uint *i, bool *chunk_found);
t_uint	get_chunks(t_chunk **chunk, t_str *splited);
t_uint	last_chunk_end(t_chunk **chunk);
t_uint	new_chunk(t_chunk	**chunk, t_uint	chunk_lim[2], t_str *splited, t_uint type);
t_uint	under_chunk(t_chunk **chunk, t_str *splited);
t_uint	check_builtins(char *str);

#endif