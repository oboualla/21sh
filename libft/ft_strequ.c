/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 03:03:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/10 17:12:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				break ;
			i++;
		}
		if (s1[i] != s2[i])
			return (0);
		return (1);
	}
	return (0);
}
