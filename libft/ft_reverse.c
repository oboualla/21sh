/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:19:23 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 00:57:34 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char const *chaine)
{
	char	*reverse;
	int		j;
	int		i;

	if (!(chaine))
		return (NULL);
	i = -1;
	j = ft_strlen(chaine);
	j--;
	if (!(reverse = (char*)ft_memalloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (++i <= j)
		reverse[i] = chaine[j - i];
	return (reverse);
}
