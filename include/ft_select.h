/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 07:15:36 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/19 14:12:41 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct		s_select
{
	struct termios	term;
	struct winsize	win;
	char			**items;
	int				*selected;
	int				n_items;
	int				pos;
}					t_select;

t_select		*g_select;
int				init_terminal_data(void);
int  			my_outc(int c);
int				get_items(int argc, char **argv);
int				term_back(void);
int				print_items();
int				voir_touche();
void			ft_ul(char *str);
void			ft_clear(void);
int				max_item_len();
#endif
