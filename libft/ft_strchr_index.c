/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:38:36 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 14:46:06 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_index(const char *str, char c)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && (!i || str[i - 1] != '\\'))
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strnchr_index(const char *str, char c, size_t n)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && i < n)
	{
		if (str[i] == c && (!i || str[i - 1] != '\\'))
			break ;
		i++;
	}
	return (i);
}
