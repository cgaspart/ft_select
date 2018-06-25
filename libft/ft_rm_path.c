/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:35:33 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/01 16:35:35 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rm_lastpath_b(t_buffer *path)
{
	int i;

	i = ft_strlen(path->buffer);
	while (path->buffer[i] != '/')
	{
		path->buffer[i] = '\0';
		i--;
	}
	path->buffer[i] = '\0';
}

char	*path_remover(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (str[len] != '/')
	{
		i++;
		len--;
	}
	res = malloc(sizeof(char) * i + 1);
	i = 0;
	len++;
	while (str[len + i] != '\0')
	{
		res[i] = str[len + i];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

char	*ft_rm_str_path(char *str)
{
	if (str == NULL)
		return (NULL);
	if (ft_strchr(str, '/'))
		return (path_remover(str));
	return (str);
}

char	**ft_rm_tab_path(char **tab)
{
	char		*buff;
	int			i;

	i = 0;
	while (tab[i])
	{
		buff = ft_strdup(tab[i]);
		free(tab[i]);
		tab[i] = ft_rm_str_path(buff);
		i++;
	}
	return (tab);
}
