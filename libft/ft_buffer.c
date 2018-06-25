/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 00:25:50 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/23 00:25:52 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rm_b_path(t_buffer *my_buffer)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(my_buffer->buffer);
	while (my_buffer->buffer[i] != '/')
		i--;
	i++;
	while (my_buffer->buffer[i + j] != '\0')
	{
		my_buffer->buffer[j] = my_buffer->buffer[i + j];
		j++;
	}
	my_buffer->buffer[j] = '\0';
}

int			ft_addstr_b(t_buffer *my_buffer, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (my_buffer->buffer[i] != '\0' && i < 4999)
		i++;
	while (str[j] != '\0' && i < 4999)
	{
		my_buffer->buffer[i + j] = str[j];
		j++;
	}
	my_buffer->buffer[i + j] = '\0';
	if (i == 4999)
		return (0);
	return (1);
}

int			ft_putstr_b(t_buffer *my_buffer, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < 4999)
	{
		my_buffer->buffer[i] = str[i];
		i++;
	}
	my_buffer->buffer[i] = '\0';
	if (i == 4999)
		return (0);
	return (1);
}

t_buffer	*ft_newbuffer(void)
{
	t_buffer *struct_buff;

	struct_buff = (t_buffer*)malloc(sizeof(t_buffer));
	ft_bzero(struct_buff->buffer, 4999);
	return (struct_buff);
}
