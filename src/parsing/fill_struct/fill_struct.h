/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/25 14:15:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_STRUCT_H
# define FILL_STRUCT_H

# include <minish.h>

struct s_chunk_utils
{
	t_uint	chunk_lim[2];
	t_str	*splited;
	t_chunk	**chunk;
};

t_uint			check_builtins(char *str);
t_uint			new_cmd(t_sh_context *shx, t_cmd **_cmd, t_str *splited);

t_uint			create_block(t_sh_context *shx, t_block **new);
t_uint			add_block(t_sh_context *shx, t_block **block);

t_uint			create_chunk(t_sh_context *shx,
					t_chunk **new, t_uint	chunk_lim[2], t_uint type);
t_uint			chunk_size(t_sh_context *shx,
					t_chunk_utils *chunk_utils,
					t_uint *i, bool *chunk_found);
t_uint			get_chunks(t_sh_context *shx, t_chunk **chunk, t_str *splited);
t_uint			last_chunk_end(t_chunk **chunk);
t_uint			new_chunk(t_sh_context *shx,
					t_chunk_utils *chunk_utils, t_uint type);
t_uint			check_builtins(char *str);
t_uint			create_s_env(t_sh_context *shx);
t_uint			get_valid_paths(t_sh_context *shx, t_str *cmd, t_str src);
t_uint			build_command(t_sh_context *shx, t_str *splited,
					t_uint *i, t_str *to_build);

#endif