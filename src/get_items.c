/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:25:08 by cgaspart          #+#    #+#             */
/*   Updated: 2018/06/25 10:25:10 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*int		max_item_len()
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (g_select->items[i])
	{
		if (res < (int)ft_strlen(g_select->items[i]))
			res = ft_strlen(g_select->items[i]);
		i++;
	}
	return (res);
}*/

int		print_items(t_env *env)
{
	t_select		*item_ptr;
	int			i;

	i = 0;
	ft_clear();
	item_ptr = env->items;
	while (item_ptr)
	{
		if (i == env->pos && item_ptr->selected)
			ft_ul(item_ptr->name);
		if (item_ptr->selected)
			ft
			ft_putstr(item_ptr->name);
		item_ptr = item_ptr->next;
		i++;
	}
	return (1);
}

void		del_item(t_env *env)
{
	t_select	*item_ptr;
	t_select	*tmp;
	int		i;

	i = 0;
	item_ptr = env->items;
	while (item_ptr->next && ++i < env->pos)
		item_ptr = item_ptr->next;
	if (item_ptr->next == NULL)
		return ;
	tmp = item_ptr->next->next;
	free(item_ptr->next->name);
	free(item_ptr->next);
	item_ptr->next = tmp;
	env->n_items--;
}

int		get_items(int argc, char **argv, t_env *env)
{
	int		i;
	t_select	*item_ptr;

	i = 1;
	if (argc < 2)
		return (ITEM_ERROR);
	env->items = (t_select*)malloc(sizeof(t_select));
	item_ptr = env->items;
	while (i != argc)
	{
		item_ptr->name = ft_strdup(argv[i]);
		((i == 1) ? (item_ptr->selected = 1) : (item_ptr->selected = 0));
		i++;
		if (i == argc)
			break ;
		item_ptr->next = (t_select*)malloc(sizeof(t_select));
		item_ptr = item_ptr->next;
	}
	item_ptr->next = NULL;
	return (1);
}
