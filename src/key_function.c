/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:43:19 by cgaspart          #+#    #+#             */
/*   Updated: 2018/07/04 05:43:21 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		space_key(int buffer2)
{
	(void)buffer2;
	selector(g_select->pos);
	return (0);
}

int		arrow_key(int buffer2)
{
	if (buffer2 == 67)
		g_select->pos++;
	if (buffer2 == 68)
		g_select->pos--;
	if (g_select->pos == -1)
		g_select->pos = g_select->n_items - 1;
	if (g_select->pos == g_select->n_items)
		g_select->pos = 0;
	return (0);
}

int		ctrld(int buffer2)
{
	if (buffer2 == 91)
	{
		term_back();
		return (1);
	}
	return (0);
}

int		other_key(int buffer2)
{
	(void)buffer2;
	return (0);
}

t_env		*init_key_func(void)
{
	int		i;
	t_env		*env;
	env = malloc(sizeof(t_env));

	i = 0;
	while (i < 32)
	{
		env->key_function[i] = &other_key;
		i++;
	}
	env->key_function[32] = &space_key;
	env->key_function[27] = &arrow_key;
	env->key_function[4] = &ctrld;
	return (env);
}
