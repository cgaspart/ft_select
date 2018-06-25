/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 07:11:30 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/23 12:03:38 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_search(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j]
					&& s2[j] && i + j < n)
			{
				if (j == ft_strlen(s2) - 1)
					return ((char*)s1 + i);
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char*)s1);
	else
		return (ft_search(s1, s2, n));
}
