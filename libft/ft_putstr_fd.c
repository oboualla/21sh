/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 22:18:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/08/10 23:16:15 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putchar_fd(str[i++], fd);
	}
}
