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

int	del_key(int buffer2, t_env *env)
{
	(void)buffer2;
	if (env->n_items == 1)
	{
		term_back(env->term);
		free_env(env);
		return (1);
	}
	del_item(env);
	return (0);
}
