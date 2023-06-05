/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:46 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 14:01:53 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_putchar_nbr(int a)
{
	a += '0';
	return (write(1, &a, 1));
}

int	ft_putnbr_printf(long n, int size)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (10);
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		size++;
	}
	if (n > 9)
	{
		size++;
		size = ft_putnbr_printf(n / 10, size);
	}
	ft_putchar_nbr(n % 10);
	return (size);
}
