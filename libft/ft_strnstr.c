/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:43:38 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/18 19:00:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t e;

	i = 0;
	if (n == 0 && to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && n)
	{
		e = 0;
		while (str[i + e] == to_find[e] && str[i + e]
				&& to_find[e] && e < n)
			e++;
		if (to_find[e] == '\0')
			return ((char *)str + i);
		i++;
		n--;
	}
	return (NULL);
}
