/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:20:52 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/22 07:10:10 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(size_t i, size_t j, char *dest, char const *s)
{
	int o;

	o = 0;
	while (i < j)
	{
		dest[o] = s[i];
		o++;
		i++;
	}
	dest[o] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;
	int		o;

	if (!s)
		return (NULL);
	i = 0;
	o = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		return (new = ft_memalloc(1));
	while (s[j - 1] == ' ' || s[j - 1] == ',' || s[j - 1] == '\n' ||
			s[j - 1] == '\t')
		j--;
	new = (char*)malloc(sizeof(*s) * (j - i + 1));
	if (new == NULL)
		return (NULL);
	new = ft_copy(i, j, new, s);
	return (new);
}
