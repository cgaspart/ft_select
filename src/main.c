/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:13:23 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/19 14:15:09 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	int no_items;

	no_items = 0;
	if (init_terminal_data())
	{
		if (get_items(argc, argv))
			key_reader();
		else
			no_items++;
	}
	term_back();
	if (no_items)
		ft_putstr("NO ITEMS");
	return (1);
}
