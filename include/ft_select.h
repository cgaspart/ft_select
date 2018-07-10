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
# define ITEM_ERROR 0
# define TERM_T_ERROR -2
# define TERM_CAP_ERROR -3
# define TERM_T_ND -4

# include "../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct			s_select
{
	char					*name;
	int					selected;
	struct s_select	*next;
}							t_select;

typedef struct			s_env
{
	int					(*key_function[129])(int buffer2, struct s_env *env);
	struct termios		term;
	struct winsize		win;
	int					n_items;
	int					pos;
	t_select				*items;
}							t_env;

int						init_terminal_data(t_env *env);
int						my_outc(int c);
int						get_items(int argc, char **argv, t_env *env);
int						term_back(struct termios term);
int						print_items();
int						key_reader(t_env *env);
void						ft_ul(char *str);
void						ft_video(char *str);
void						ft_ul_video(char *str);
void						ft_clear(void);
int						max_item_len();
void						selector(int pos);
void						init_key_func(t_env *env);
int						other_key(int buffer2, t_env *env);
int						ctrld(int buffer2, t_env *env);
int						arrow_key(int buffer2, t_env *env);
int						space_key(int buffer2, t_env *env);
void						del_item(t_env *env);
int						del_key(int buffer2, t_env *env);
void						free_env(t_env *env);
void						free_items(t_env *my_env);
int						setup_error(int error, t_env *env);
#endif
