/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:05:55 by oboualla          #+#    #+#             */
/*   Updated: 2019/09/17 21:05:57 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strccmp(const char *str, const char *s2, char c)
{
	size_t	i;

	i = 0;
	while (str[i + 1] != c && (unsigned char)str[i] == (unsigned char)s2[i]
			&& str[i] && s2[i])
		i++;
	return ((unsigned char)str[i] - (unsigned char)s2[i]);
}
