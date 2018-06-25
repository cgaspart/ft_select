/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:28:44 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/03 10:30:31 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_issame(char *first, char *second)
{
	int i;

	i = 0;
	if (ft_strlen(first) != ft_strlen(second))
		return (0);
	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return (0);
		i++;
	}
	return (1);
}
