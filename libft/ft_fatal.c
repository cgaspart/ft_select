/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:51:18 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/22 10:51:19 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fatal(char *error_mess, char *this)
{
	ft_putstr(error_mess);
	if (this != NULL)
		ft_putstr(this);
	exit(1);
}
