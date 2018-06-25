/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:12:40 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/30 08:30:28 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_space(int maxspace, int len)
{
	if (len != 0)
	{
		while (len >= 1 && maxspace > 0)
		{
			len--;
			maxspace--;
		}
	}
	else
		maxspace--;
	while (maxspace)
	{
		ft_putchar(' ');
		maxspace--;
	}
}
