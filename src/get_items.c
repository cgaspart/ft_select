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

int		total_len()
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (g_select->items[i])
	{
		res += ft_strlen(g_select->items[i]);
		i++;
	}
	res += g_select->n_items;
	return (res - 1);
}

void	print_items()
{
	int i;
	char *res;

	i = 0;
	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 0, my_outc);
	while (g_select->items[i])
	{
		ioctl(2, TIOCGWINSZ, &g_select->win);
		if (i == g_select->pos)
		{
			tputs(tgetstr("us", NULL), 1, my_outc);
			ft_putstr(g_select->items[i]);
			tputs(tgetstr("ue", NULL), 1, my_outc);
		}
		else
			ft_putstr(g_select->items[i]);
		if (g_select->win.ws_row < total_len())
		{
			tputs(res, 0, my_outc);
			ft_putchar('\n');
		}
		else
			ft_putchar(' ');
		i++;
	}
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
