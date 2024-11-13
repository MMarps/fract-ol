/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:46:16 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/07/25 18:51:41 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_summary(va_list args, const char **format)
{
	int	count;

	count = 0;
	if (**format == '%')
		count = write(1, "%", 1);
	if (**format == 'c')
		count = ft_putchar_ct(va_arg(args, int));
	if (**format == 's')
		count = ft_putstr_ct(va_arg(args, char *));
	if (**format == 'd' || **format == 'i')
		count = ft_putnbr_ct(va_arg(args, int));
	if (**format == 'u')
		count = ft_putunsigned_int(va_arg(args, unsigned int));
	if (**format == 'x')
		count = ft_hexa(va_arg(args, unsigned int), 0);
	if (**format == 'X')
		count = ft_hexa(va_arg(args, unsigned int), 1);
	if (**format == 'p')
		count = ft_putptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_summary(args, &format);
			format++;
		}
		else
		{
			count += ft_putchar_ct(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
