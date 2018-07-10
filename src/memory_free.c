/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:20:55 by cgaspart          #+#    #+#             */
/*   Updated: 2018/07/08 18:20:57 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_items(t_env *env)
{
	t_select	*buff;

	buff = env->items;
	while (env->items)
	{
		free(env->items->name);
		buff = env->items->next;
		free(env->items);
		env->items = buff;
	}
}

void	free_env(t_env *env)
{
	if (env && env->items != NULL)
		free_items(env);
	if (env != NULL)
		free(env);
}
