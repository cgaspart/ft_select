/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:16:14 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/29 14:16:16 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int     key_reader()
{
	char     buffer[3];

	while (1)
	{
		print_items();
		read(1, buffer, 3);
		if (buffer[0] == 32)
			selector(g_select->pos);
		if (buffer[0] == 27 && buffer[2] == 68)
			g_select->pos--;
		if (buffer[0] == 27 && buffer[2] == 67)
			g_select->pos++;
		if (g_select->pos == -1)
			g_select->pos = g_select->n_items - 1;
		if (g_select->pos == g_select->n_items)
			g_select->pos = 0;
		if (buffer[0] == 4 && buffer[1] == 91)
		{
			term_back();
			return (1);
		}
	}
	return (0);
}
