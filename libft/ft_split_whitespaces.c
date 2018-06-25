/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:17:15 by cgaspart          #+#    #+#             */
/*   Updated: 2017/09/19 12:01:40 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_malloc_line(char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		if (*str == '\n' || *str == '\t' || *str == ' ')
			str++;
		else
		{
			res++;
			while (*str != '\n' && *str != '\t' && *str != ' ' && *str)
				str++;
		}
	}
	return (res);
}

int		ft_malloc_word(char *str)
{
	int i;

	i = 0;
	while (*str && *str != '\n' && *str != '\t' && *str != ' ')
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_cp(char *str, char **res)
{
	int i;
	int i2;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i2 = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		while (str[i] != ' ' && str[i] != '\n' &&
				str[i] != '\t' && str[i] != '\0')
		{
			res[j][i2] = str[i];
			i++;
			i2++;
		}
		if (i2 > 0)
		{
			res[j][i2] = '\0';
			j++;
		}
	}
	res[j] = 0;
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	char	*tmp;
	char	**tmp2;

	tmp = str;
	res = (char**)malloc(sizeof(char*) * (ft_malloc_line(str) + 1));
	tmp2 = res;
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		else if (*str)
		{
			*res = malloc(sizeof(char) * ft_malloc_word(str) + 1);
			res++;
			while (*str && *str != '\n' && *str != '\t' && *str != ' ')
				str++;
		}
	}
	ft_cp(tmp, tmp2);
	return (tmp2);
}
