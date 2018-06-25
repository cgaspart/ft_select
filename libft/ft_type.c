/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:17:24 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:13:36 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char	ft_type(char *dirname)
{
	struct stat fstat;

	if (lstat(dirname, &fstat) == -1)
		return (0);
	if (S_ISDIR(fstat.st_mode))
		return ('d');
	else if (S_ISLNK(fstat.st_mode))
		return ('l');
	else if (S_ISSOCK(fstat.st_mode))
		return ('s');
	else if (S_ISFIFO(fstat.st_mode))
		return ('p');
	else if (S_ISCHR(fstat.st_mode))
		return ('c');
	else if (S_ISBLK(fstat.st_mode))
		return ('b');
	else if (S_ISREG(fstat.st_mode))
		return ('-');
	else
		return (0);
}
