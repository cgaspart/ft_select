/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:31:01 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/27 18:31:03 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		malloc_tab(void)
{
	int i;

	i = 0;
	g_select->selected = malloc(sizeof(int) * g_select->n_items);
	while (i < g_select->n_items)
	{
		g_select->selected[i] = 0;
		i++;
	}
}

void			selector(int pos)
{
	if (g_select->selected == NULL)
		malloc_tab();
	g_select->selected[pos] = !g_select->selected[pos];
}
