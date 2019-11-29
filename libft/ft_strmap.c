/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:05:08 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 13:54:39 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int			i;
	char		*st2;
	int			size;

	if (!(str))
		return (NULL);
	size = ft_strlen(str);
	if (!(st2 = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (st2)
	{
		while (i < size)
		{
			st2[i] = f(str[i]);
			i++;
		}
		st2[i] = '\0';
		return (st2);
	}
	return (NULL);
}
