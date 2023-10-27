/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:32:13 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/27 11:27:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	skip_space_set_sign(const char	**str, int *sign)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

long long	ft_strtoll(const char *str)
{
	int					sign;
	unsigned long long	result;

	errno = 0;
	sign = 1;
	result = 0;
	skip_space_set_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (sign > 0 && (result > LLONG_MAX / 10
				|| (result == LLONG_MAX / 10 && *str - '0' > LLONG_MAX % 10)))
			return (errno = ERANGE, LLONG_MAX);
		else if (sign < 0 && (result > (unsigned long long)LLONG_MIN / 10
				|| (result == (unsigned long long)LLONG_MIN / 10
					&& (unsigned long long)(*str - '0') \
				> (unsigned long long)LLONG_MIN % 10)))
			return (errno = ERANGE, LLONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((long long)(result * sign));
}

long long	ft_atoll(const char *str)
{
	long long	nb;
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
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
