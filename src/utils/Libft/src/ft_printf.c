/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:24:54 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 14:04:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_find_the_type(char c, va_list var, int size)
{
	if (c == 'c')
		size += ft_putchar_printf((int)va_arg(var, int));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr_printf((int)va_arg(var, int), 0) + 1;
	else if (c == 's')
		size += ft_putstr_printf((char *)va_arg(var, char *));
	else if (c == 'p')
		size += ft_putptr_printf((const void *)va_arg(var, const void *), \
		"0123456789abcdef");
	else if (c == 'u')
		size += ft_putnbr_base_printf((unsigned int)va_arg(var, unsigned int), \
		"0123456789");
	else if (c == 'x')
		size += ft_putnbr_base_printf((unsigned int)va_arg(var, unsigned int), \
		"0123456789abcdef");
	else if (c == 'X')
		size += ft_putnbr_base_printf((unsigned int)va_arg(var, unsigned int), \
		"0123456789ABCDEF");
	return (size);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		size;
	va_list	var;

	i = 0;
	size = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0' || str[i] == ' ' || str[i] == '%')
				size += write(1, "%", 1);
			size = ft_find_the_type(str[i++], var, size);
			continue ;
		}
		else
			size += write(1, &str[i++], 1);
	}
	return (va_end(var), size);
}
