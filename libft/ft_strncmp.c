/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:40:12 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/04 15:39:55 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!str || !s2)
		return (0);
	while (i < (n - 1) && (unsigned char)str[i] == (unsigned char)s2[i]
			&& str[i] && s2[i])
		i++;
	if (n > 0)
		return ((unsigned char)str[i] - (unsigned char)s2[i]);
	else
		return (0);
}
