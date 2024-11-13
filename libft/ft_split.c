/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:37:20 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/05/29 14:26:24 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char const c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_freetab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_insert(char **tab, char const *str, size_t size, size_t count)
{
	size_t	i;

	i = 0;
	tab[count] = ft_calloc(sizeof(char), (size + 1));
	if (!tab[count])
		return ;
	while (i < size)
	{
		tab[count][i] = str[i];
		i++;
	}
	tab[count][i] = '\0';
}

static int	ft_fill_tab(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	size;

	count = 0;
	while (*s)
	{
		size = 0;
		if (*s != c)
		{
			while (s[size] && s[size] != c)
				size++;
			ft_insert(tab, s, size, count);
			if (!tab[count])
			{
				ft_freetab(tab, count);
				return (0);
			}
			count++;
			s += size;
		}
		else
			s++;
	}
	tab[count] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	tab = ft_calloc(sizeof(char *), (size + 1));
	if (!tab)
	{
		return (NULL);
	}
	if (ft_fill_tab(tab, s, c))
	{
		return (tab);
	}
	return (NULL);
}
