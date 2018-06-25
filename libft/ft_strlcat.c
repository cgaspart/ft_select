/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 06:46:34 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/23 12:19:56 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t i;
	size_t j;
	size_t result;

	i = 0;
	j = 0;
	result = ft_strlen(src);
	while (dest[i] && i < count)
		i++;
	if (count > 0)
	{
		while (src[j] && i < count - 1)
		{
			dest[i++] = src[j++];
		}
	}
	if (j > 0)
	{
		dest[i] = '\0';
		return (result + i - j);
	}
	return (result + i);
}
