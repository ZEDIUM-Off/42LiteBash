/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:42:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/16 12:45:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_file	new_file(t_str name)
{
	t_file	file;

	file.file_name = name;
	file.fd = -1;
	file.is_open = false;
	return (file);
}
