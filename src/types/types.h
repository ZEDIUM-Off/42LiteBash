/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:59:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/07 20:31:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <minish.h>

typedef unsigned int				t_uint;
typedef unsigned char				t_uchar;
typedef char						*t_str;

typedef struct s_sh_context			t_sh_context;
typedef struct s_pipeline			t_pipeline;
typedef struct s_garbage_collector	t_garbage_collector;
typedef struct s_ptr				t_ptr;
typedef struct s_error_handler		t_error_handler;
typedef struct s_tracker			t_tracker;
typedef struct s_parsing_data		t_p_data;
typedef struct	s_list			t_list;
typedef struct	s_dlist			t_dlist;

typedef void (*						t_free_func)(void *ptr);
typedef void *(*					t_malloc_func)(size_t size);

#endif