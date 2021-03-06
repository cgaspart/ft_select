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

static t_env	*setup_env(int argc, char **argv)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->pos = 0;
	env->n_items = argc - 1;
	if (setup_error(init_terminal_data(env), env) &&
	setup_error(get_items(argc, argv, env), env))
		return (env);
	free_env(env);
	return (NULL);
}

int				main(int argc, char **argv)
{
	t_env		*env;

	if ((env = setup_env(argc, argv)))
		key_reader(env);
	return (1);
}
