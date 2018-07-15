/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:47:39 by cgaspart          #+#    #+#             */
/*   Updated: 2018/07/05 15:47:41 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	return_key(int buffer2, t_env *env)
{
	t_select *item_ptr;

	(void)buffer2;
	item_ptr = env->items;
	term_back(env->term);
	while (item_ptr)
	{
		if (item_ptr->selected)
		{
			ft_putstr_fd(item_ptr->name, 2);
			(item_ptr->next ? (ft_putchar_fd(' ', 2)) : (ft_putchar_fd('\n', 2)));
		}
		item_ptr = item_ptr->next;
	}
	free_env(env);
	return (1);
}

int	del_key(int buffer2, t_env *env)
{
	if (env->n_items == 1)
		ctrld(buffer2, env);
	del_item(env);
	return (0);
}
