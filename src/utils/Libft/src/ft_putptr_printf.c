/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:56:22 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 14:01:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putptr_printf(const void *nbr, char *base)
{
	long			i;
	char			nbr_print[250];
	unsigned long	ptr;
	int				size;

	size = 0;
	ptr = (unsigned long) nbr;
	i = 0;
	write(1, "0x", 2);
	if (ptr == 0)
		return (write(1, "0", 1), 3);
	while (ptr > 0)
	{
		nbr_print[i++] = base[(ptr % 16)];
		ptr /= 16;
	}
	i--;
	while (i >= 0)
	{
		write (1, &nbr_print[i--], 1);
		size++;
	}
	return (size + 2);
}
