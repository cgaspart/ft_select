/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:54:14 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/13 11:26:13 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	int				idest;

	i = 0;
	idest = ft_strlen(dest);
	while (i < n && src[i] != '\0')
	{
		dest[idest] = src[i];
		i++;
		idest++;
	}
	dest[idest] = '\0';
	return (dest);
}
