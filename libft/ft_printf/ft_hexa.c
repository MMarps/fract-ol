/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:54:57 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/06/09 18:41:03 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n, int i)
{
	char	*hex;
	int		count;

	count = 0;
	if (i == 0)
		hex = "0123456789abcdef";
	else if (i == 1)
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_hexa(n / 16, i);
		count += ft_hexa(n % 16, i);
	}
	else
		count += ft_putchar_ct(hex[n]);
	return (count);
}

int	ft_hexa_llong(unsigned long long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_hexa_llong(n / 16);
		count += ft_hexa_llong(n % 16);
	}
	else
		count += ft_putchar_ct(hex[n]);
	return (count);
}
