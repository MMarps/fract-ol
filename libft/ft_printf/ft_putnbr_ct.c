/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:48:40 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/07/25 18:22:21 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ct(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr_ct("-2147483648");
		return (count = 11);
	}
	else if (n < 0)
	{
		n = -n;
		count += ft_putchar_ct('-');
	}
	if (n > 9)
	{
		count += ft_putnbr_ct((n / 10));
		count += ft_putnbr_ct((n % 10));
	}
	else
		count += ft_putchar_ct(n + '0');
	return (count);
}

int	ft_putunsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned_int(n / 10);
		count += ft_putunsigned_int(n % 10);
	}
	else
		count += ft_putchar_ct(n + '0');
	return (count);
}
