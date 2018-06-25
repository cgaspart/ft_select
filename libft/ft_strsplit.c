/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:50:30 by cgaspart          #+#    #+#             */
/*   Updated: 2017/11/22 07:09:11 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_parts(const char *s, char c)
{
	int cnt;
	int verif;

	verif = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (verif == 1 && *s == c)
			verif = 0;
		if (verif == 0 && *s != c)
		{
			verif = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_wlen(const char *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	nb_word = ft_cnt_parts((const char *)s, c);
	res = (char **)malloc(sizeof(*res) *
			(ft_cnt_parts((const char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (res[i] == NULL)
			return (NULL);
		i++;
		s = s + ft_wlen(s, c);
	}
	res[i] = NULL;
	return (res);
}
