/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:20:20 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/24 16:34:13 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsubdel(char *str, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) - (end - start) + 1);
	while (str[i])
	{
		if (i == start)
			i = end;
		if (str[i] == '\0')
			break ;
		ret[j++] = str[i++];
	}
	free(str);
	return (ret);
}
