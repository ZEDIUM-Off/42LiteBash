/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:59:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 11:28:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// # include <minish.h>

typedef unsigned int				t_uint;
typedef unsigned char				t_uchar;
typedef char						*t_str;

typedef struct s_sh_context			t_sh_context;
typedef struct s_file				t_file;
typedef struct s_garbage_collector	t_garbage_collector;
typedef struct s_ptr				t_ptr;
typedef struct s_list				t_list;
typedef struct s_dlist				t_dlist;
typedef struct s_block				t_block;
typedef struct s_redirect			t_redirect;
typedef struct s_pipeline			t_pipeline;
typedef struct s_cmd				t_cmd;
typedef struct s_process			t_process;
typedef struct s_quote_test			t_quote_test;
typedef struct s_status_env			t_status_env;
typedef struct s_export				t_export;
typedef struct s_chunk_utils		t_chunk_utils;

typedef void (*						t_free_func)(
	t_sh_context	*shx,
	void *ptr
);
typedef void *(*					t_malloc_func)(
	t_sh_context	*shx,
	size_t size,
	bool count
);

#endif