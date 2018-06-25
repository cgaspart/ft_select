/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:56:45 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:34 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (fraiche);
}
