/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:11:17 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/22 06:59:36 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int s1len;
	int s2len;
	int i;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	if (s1len != s2len)
		return (0);
	else
	{
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
}
