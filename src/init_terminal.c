/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:15:32 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/19 14:15:34 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int  my_outc(int c)
{
	ft_putchar((char)c);
	return (1);
}

int term_back()
{
	tputs(tgetstr("ve", NULL), 1, my_outc);
	tputs(tgetstr("te", NULL), 1, my_outc);
	g_select->term.c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(2, TCSANOW, &g_select->term)) == -1)
		return (-1);
	return (0);
}

/*void	interrogate_terminal()
{
	char *temp;

	cl_string = tgetstr ("cl", BUFFADDR);
	cm_string = tgetstr ("cm", BUFFADDR);
	auto_wrap = tgetflag ("am");
	height = tgetnum ("li");
	width = tgetnum ("co");
	temp = tgetstr ("pc", BUFFADDR);
	PC = temp ? *temp : 0;
	BC = tgetstr ("le", BUFFADDR);
	UP = tgetstr ("up", BUFFADDR);
}*/

int	init_terminal_data()
{
	char		*termtype;
	int			success;

	g_select = malloc(sizeof(t_select));
	termtype = getenv ("TERM");
	if (termtype == 0)
		ft_fatal("Specify a terminal type with 'setenv TERM'.", NULL);
	success = tgetent (NULL, termtype);
	if (success < 0)
		ft_fatal("Could not access the termcap data base.", NULL);
	if (success == 0)
		ft_fatal("Terminal type is not defined:", termtype);
	if (tcgetattr(2, &g_select->term) == -1)
		return (-1);
	g_select->term.c_lflag &= ~(ICANON | ECHO);
	g_select->term.c_cc[VMIN] = 1;
	g_select->term.c_cc[VTIME] = 0;
// On applique les changements :
	if (tcsetattr(2, TCSANOW, &g_select->term) == -1)
		ft_fatal("Can't init terminal conf", NULL);
	tputs(tgetstr("ti", NULL), 1, my_outc);
	tputs(tgetstr("vi", NULL), 1, my_outc);
	return (1);
}

/*int     voir_touche()
{
	char     buffer[3];

	while (1)
	{
		read(1, buffer, 3);
		if (buffer[0] == 27 && buffer[2] == 68)
			print_cursor_loop(-1, 0);
		if (buffer[0] == 27 && buffer[2] == 67)
			print_cursor_loop(1, 0);
		if (buffer[0] == 27 && buffer[2] == 65)
			print_cursor_loop(0, -1);
		if (buffer[0] == 27 && buffer[2] == 66)
			print_cursor_loop(0, 1);
		if (buffer[0] == 4 && buffer[1] == 91)
		{
			ft_putnbr(term_back());
			return (1);
		}
	}
	return (0);
}*/

/*void	print_cursor_loop(int x, int y)
{

	g_select->pos_x += x;
	g_select->pos_y += y;
	tputs(cl_string, 0, my_outc);
	tputs(tgoto(cm_string, g_select->pos_x, g_select->pos_y), 1, my_outc);
}*/
