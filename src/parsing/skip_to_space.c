/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:36:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/27 15:40:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	skip_to_space(t_str str, t_uint *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t'
		&& get_meta_char(&str[*i]) == NONE)
		*i += 1;
}
