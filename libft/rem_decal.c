/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_decal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:04:10 by kbahrar           #+#    #+#             */
/*   Updated: 2019/09/14 20:04:35 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rem_decal(int place, char ch, char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char*)malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (i == place)
		{
			new_str[j++] = ch;
		}
		new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}
