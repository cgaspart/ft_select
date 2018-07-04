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

int		key_reader()
{
	char		buffer[3];
	t_env		*env;

	env = init_key_func();
	while (1)
	{
		print_items();
		read(1, buffer, 3);
		if (env->key_function[(int)buffer[0]]
			((buffer[0] == 4) ? (int)buffer[1] : (int)buffer[2]))
			return (1);
	}
	return (0);
}
