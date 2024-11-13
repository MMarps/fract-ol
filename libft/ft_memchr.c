/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:52:25 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/05/22 17:06:19 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		chr;
	const unsigned char	*str;

	chr = c;
	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
