/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:38:36 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/27 17:48:10 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_index(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && (!i || str[i - 1] != '\\'))
			break ;
		i++;
	}
	if (!str[i])
		return (0);
	return (i);
}
