/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 00:48:28 by cgaspart          #+#    #+#             */
/*   Updated: 2018/07/09 00:48:30 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		no_item(t_env *env)
{
	term_back(env->term);
	free_env(env);
	ft_fatal("USAGE: ./ft_select [ITEM1] [ITEM2] ...\n", NULL);
}

static void		term_erro(int error, t_env *env)
{
	term_back(env->term);
	free_env(env);
	if (error == TERM_T_ERROR)
		ft_fatal("Specify a terminal type with 'setenv TERM'.\n", NULL);
	if (error == TERM_CAP_ERROR)
		ft_fatal("Could not access the termcap data base.\n", NULL);
	if (error == TERM_T_ND)
		ft_fatal("Terminal type is not defined:\n", getenv("TERM"));
}

int				setup_error(int error, t_env *env)
{
	if (error == 1)
		return (1);
	((error == ITEM_ERROR) ? no_item(env) : term_erro(error, env));
	return (0);
}
