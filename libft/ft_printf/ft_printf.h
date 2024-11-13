/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:56:52 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/07/30 17:57:39 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_summary(va_list args, const char **str);

int	ft_hexa(unsigned int n, int i);

int	ft_hexa_llong(unsigned long long n);

int	ft_putstr_ct(char *str);

int	ft_putnbr_ct(int n);

int	ft_putchar_ct(char c);

int	ft_putunsigned_int(unsigned int n);

int	ft_putptr(void *ptr);

#endif