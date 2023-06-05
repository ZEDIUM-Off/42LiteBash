/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:22:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/11 16:32:20 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *str);
int	ft_printf(const char *str, ...);
int	ft_putnbr_printf(long n, int size);
int	ft_putptr_printf(const void *nbr, char *base);
int	ft_putnbr_base_printf(unsigned int nbr, char *base);

#endif
