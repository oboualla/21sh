/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 01:51:45 by oboualla          #+#    #+#             */
/*   Updated: 2019/05/21 06:35:42 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	unsigned int nbr;
	unsigned int n;

	n = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	nbr = nb;
	while (n * n < nbr)
		n++;
	if (n * n == nbr)
		return (n);
	return (0);
}
