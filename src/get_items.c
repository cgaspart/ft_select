/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:25:08 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/25 10:25:10 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		max_item_len()
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (g_select->items[i])
	{
		if (res < (int)ft_strlen(g_select->items[i]))
			res = ft_strlen(g_select->items[i]);
		i++;
	}
	return (res);
}

int		print_items()
{
	int i;
	char *res;

	i = 0;
	ft_clear();
	while (g_select->items[i])
	{
		ioctl(2, TIOCGWINSZ, &g_select->win);
		if (i == g_select->pos)
			ft_ul(g_select->items[i]);
		else
			ft_putstr(g_select->items[i]);
		if (g_select->win.ws_row < max_item_len())
		{
			tputs(res, 0, my_outc);
			ft_putchar('\n');
		}
		else
			ft_putchar(' ');
		i++;
	}
	return (1);
}

int		get_items(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	g_select->items = (char**)malloc(sizeof(char*) * argc);
	while (i + 1 != argc)
	{
		g_select->items[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	g_select->items[i] = NULL;
	g_select->pos = 0;
	g_select->n_items = ft_tablen(g_select->items);
	return (1);
}
