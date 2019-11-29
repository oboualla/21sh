/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:23:59 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/15 22:57:37 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *tab;

	if (!(tab = (char *)malloc(sizeof(char ) * size)))
		return (NULL);
	while (size--)
		tab[size] = 0;
	return (tab);
}
