/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:38:11 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 21:39:36 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_char(char const *str)
{
	int i;
	int count_size;
	int j;

	if (!str)
		return (0);
	j = 0;
	i = 0;
	count_size = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[j] != '\0')
		j++;
	j--;
	while (str[j] == '\n' || str[j] == '\t' || str[j] == ' ')
		j--;
	while (i <= j)
	{
		count_size++;
		i++;
	}
	return (count_size);
}
