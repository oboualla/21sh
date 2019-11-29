/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:55:52 by kbahrar           #+#    #+#             */
/*   Updated: 2019/07/10 16:01:50 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chreplace(char *str, char origin, char cpy)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == origin)
			str[i] = cpy;
		i++;
	}
	return (str);
}
