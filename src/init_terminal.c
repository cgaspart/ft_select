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

int				term_back(struct termios term)
{
	tputs(tgetstr("ve", NULL), 1, my_outc);
	tputs(tgetstr("te", NULL), 1, my_outc);
	term.c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(2, TCSANOW, &term)) == -1)
		return (-1);
	return (0);
}

static void		set_terminal(struct termios term)
{
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(2, TCSANOW, &term) == -1)
		ft_fatal("Can't init terminal conf", NULL);
	tputs(tgetstr("ti", NULL), 1, my_outc);
	tputs(tgetstr("vi", NULL), 1, my_outc);
}

int				init_terminal_data(t_env *env)
{
	char			*termtype;
	int			success;

	termtype = getenv("TERM");
	if (termtype == 0)
		return (TERM_T_ERROR);
	success = tgetent(NULL, termtype);
	if (success < 0)
		return (TERM_CAP_ERROR);
	if (success == 0)
		return (TERM_T_ND);
	if (tcgetattr(2, &env->term) == -1)
		return (-1);
	set_terminal(env->term);
	return (1);
}
