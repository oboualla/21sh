/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:38:18 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/03 00:16:44 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int		a;
	int					b;
	int					i;

	b = 1;
	a = 0;
	i = 0;
	i = ft_skip_sep(str, " \t\v\n\r\f");
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (a * b);
}
