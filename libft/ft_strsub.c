/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:00 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/15 11:51:15 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	fraiche = (char*)malloc(sizeof(char) * len + 1);
	if (fraiche == NULL)
		return (NULL);
	while (i < len)
	{
		fraiche[i] = s[start + i];
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
