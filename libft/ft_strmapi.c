/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 08:31:12 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/06 14:21:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int i, char c))
{
	int			i;
	int			size;
	char		*tab;

	if (str == NULL)
		return (0);
	size = ft_strlen(str);
	if (!(tab = (char *)malloc(sizeof(char) + 1 * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = f(i, str[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
