/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:15:28 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/11 13:39:38 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)str2;
	s = (unsigned char *)str1;
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (s);
}
