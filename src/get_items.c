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
	ft_puttab(g_select->items);
	return (1);
}
