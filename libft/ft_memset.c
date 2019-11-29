/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:25:04 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/20 11:37:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int arg, size_t nb)
{
	size_t				i;
	unsigned char		*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < nb)
	{
		s[i] = (unsigned char)arg;
		i++;
	}
	return (s);
}
