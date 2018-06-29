/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 09:57:59 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/26 09:58:01 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int  my_outc(int c)
{
	ft_putchar((char)c);
	return (1);
}

void	ft_clear(void)
{
	char *res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 0, my_outc);
}

void	ft_ul_video(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_outc);
	tputs(tgetstr("mr", NULL), 1, my_outc);
	ft_putstr(str);
	tputs(tgetstr("me", NULL), 1, my_outc);
	tputs(tgetstr("ue", NULL), 1, my_outc);
}

void	ft_ul(char *str)
{
	tputs(tgetstr("us", NULL), 1, my_outc);
	ft_putstr(str);
	tputs(tgetstr("ue", NULL), 1, my_outc);
}

void	ft_video(char *str)
{
	tputs(tgetstr("mr", NULL), 1, my_outc);
	ft_putstr(str);
	tputs(tgetstr("me", NULL), 1, my_outc);
}
