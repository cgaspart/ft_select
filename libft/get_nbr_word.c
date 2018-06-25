/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:16:36 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/03 14:16:39 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_nbr_word(char *str)
{
	int i;
	int nbr;

	i = 0;
	if (str == NULL)
		return (0);
	nbr = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			nbr++;
		i++;
	}
	return (nbr);
}
