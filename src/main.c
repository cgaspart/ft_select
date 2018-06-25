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
	init_terminal_data();
	if (!get_items(argc, argv))
		ft_putstr("NO ITEMS");
	sleep(2);
	term_back();
	return (1);
}
