/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:02:09 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/20 20:02:11 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_str_fjoin(char *s1, char *s2, int i)
{
	char	*fraiche;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	fraiche = ft_memalloc(len);
	if (fraiche == NULL)
		return (NULL);
	ft_strcat(fraiche, s1);
	ft_strcat(fraiche, s2);
	fraiche[len] = '\0';
	if (i == 1)
		free(s1);
	if (i == 2)
		free(s2);
	if (i == 3)
	{
		free(s1);
		free(s2);
	}
	return (fraiche);
}
