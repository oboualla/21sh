/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:45:20 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/27 17:15:55 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>

unsigned int	ft_getchr(void)
{
	struct termios	trm;
	struct termios	bckp;
	char			buff[4];

	if (tcgetattr(0, &trm) == -1 || tcgetattr(0, &bckp) == -1)
		return (0);
	trm.c_lflag &= ~(ICANON);
	trm.c_lflag &= ~(ECHO);
	if (tcsetattr(0, 0, &trm) == -1)
		return (0);
	ft_bzero((void*)buff, 4);
	if (read(0, buff, 4) == -1)
		return (0);
	if (tcsetattr(0, 0, &bckp) == -1)
		return (0);
	return (*(unsigned int*)buff);
}
