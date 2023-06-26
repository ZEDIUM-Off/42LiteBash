/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:42:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/26 15:47:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_file	new_file(t_str name)
{
	t_file	file;

	file.file_name = ft_strdup(name);
	file.fd = -1;
	file.is_open = false;
	return (file);
}
