/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:16:14 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/29 14:16:16 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		key_reader(t_env *env)
{
	char		buffer[3];
	t_key		*key_ptr;

	key_ptr = init_key_func();
	while (1)
	{
		print_items(env);
		read(1, buffer, 3);
		if (((key_ptr->key_function)[(int)buffer[0]])
		(((buffer[0] == 4) ? (int)buffer[1] : (int)buffer[2]), env))
			return (1);
		if (env->pos == -1)
				env->pos = env->n_items - 1;
		if (env->pos == env->n_items)
				env->pos = 0;
	}
	return (0);
}
