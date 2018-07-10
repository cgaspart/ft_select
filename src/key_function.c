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

int		space_key(int buffer2, t_env *env)
{
	t_select		*item_ptr;
	int i;

	i = 0;
	ft_putstr("YO");
	(void)buffer2;
	item_ptr = env->items;
	while (++i < env->pos)
		item_ptr = item_ptr->next;
	item_ptr->selected = !item_ptr->selected;
	env->pos++;
	return (0);
}

int		arrow_key(int buffer2, t_env *env)
{
	if (buffer2 == 67)
		env->pos++;
	if (buffer2 == 68)
		env->pos--;
	return (0);
}

int		ctrld(int buffer2, t_env *env)
{
	/*if (buffer2 == 91)
	{*/
		(void)buffer2;
		free_env(env);
		term_back(env->term);
		return (1);
	//}
	return (0);
}

int		other_key(int buffer2, t_env *env)
{
	(void)buffer2;
	(void)env;
	return (0);
}

void		init_key_func(t_env *env)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		env->key_function[i] = &other_key;
		i++;
	}
	env->key_function[32] = &space_key;
	env->key_function[27] = &arrow_key;
	env->key_function[4] = &ctrld;
	env->key_function[127] = &del_key;
	env->key_function[126] = &del_key;
}
