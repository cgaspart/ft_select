/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:12:49 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/10 08:46:43 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *line, int len)
{
	char*buff;

	if (line == NULL)
	{
		line = (char*)malloc(sizeof(char) * len + 1);
	}
	else
	{
		buff = ft_strdup(line);
		free(line);
		line = malloc(sizeof(char) * (ft_strlen(buff) + len));
		ft_strcpy(line, buff);
		free(buff);
	}
	return (line);
}
