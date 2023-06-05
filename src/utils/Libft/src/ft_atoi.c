/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:30:15 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/17 12:30:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_overflow(int sign, long long int nb, const char *str)
{
	if (nb != (nb * 10 + *str - '0') / 10)
	{
		if (sign == -1)
			return (0);
		if (sign == 1)
			return (-1);
	}
	return (2);
}

int	ft_atoi(const char *str)
{
	long int	nb;
	int			sign;
	int			n;

	nb = 0;
	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (++n > 1)
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ft_overflow(sign, nb, str) <= 0)
			return (ft_overflow(sign, nb, str));
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
