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

typedef struct			s_select
{
	struct termios		term;
	struct winsize		win;
	char					**items;
	int					*selected;
	int					n_items;
	int					pos;
}							t_select;
typedef struct			s_env
{
	int					(*key_function[33])(int buffer2);
}							t_env;

t_select					*g_select;
int						init_terminal_data(void);
int						my_outc(int c);
int						get_items(int argc, char **argv);
int						term_back(void);
int						print_items();
int						key_reader();
void						ft_ul(char *str);
void						ft_video(char *str);
void						ft_ul_video(char *str);
void						ft_clear(void);
int						max_item_len();
void						selector(int pos);
t_env						*init_key_func(void);
int						other_key(int buffer2);
int						ctrld(int buffer2);
int						arrow_key(int buffer2);
int						space_key(int buffer2);
#endif
