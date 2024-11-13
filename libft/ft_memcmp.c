/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:56:17 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/05/22 18:06:03 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *st1, const void *st2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = st1;
	s2 = st2;
	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
