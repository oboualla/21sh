/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:44:53 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/04 00:20:32 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int		nb;
	char				a;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	nb = n;
	if (nb < 10)
	{
		a = nb + '0';
		ft_putchar_fd(a, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		a = nb % 10 + '0';
		ft_putchar_fd(a, fd);
	}
}
