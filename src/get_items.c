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

	i = 0;
	ft_clear();
	while (g_select->items[i])
	{
		ioctl(2, TIOCGWINSZ, &g_select->win);
		if (g_select->selected != NULL && g_select->selected[i] == 1)
		{
			if (i == g_select->pos)
				ft_ul_video(g_select->items[i]);
			else
				ft_video(g_select->items[i]);
		}
		else if (i == g_select->pos)
			ft_ul(g_select->items[i]);
		else
			ft_putstr(g_select->items[i]);
		ft_putchar(' ');
		i++;
	}
	i = 0;
	ft_putstr("\n\n\n n_items : ");
	ft_putnbr(g_select->n_items);
	ft_putstr("\n My pos : ");
	ft_putnbr(g_select->pos);
	ft_putstr("\n My select tab : ");
	if (g_select->selected != NULL)
	{
		while (i < g_select->n_items)
		{
			ft_putstr("| ");
			ft_putnbr(g_select->selected[i]);
			ft_putchar(' ');
			i++;
		}
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
