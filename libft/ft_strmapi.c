/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:38:04 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/15 10:04:01 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fraiche;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	fraiche = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (fraiche == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		fraiche[i] = f(i, s[i]);
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
