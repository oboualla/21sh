/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:35:58 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/15 20:18:23 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *str2, size_t nb)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (nb == 0)
		return (str);
	while (str[i])
		i++;
	while (j < nb && str2[j] != '\0')
	{
		str[i] = str2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}
