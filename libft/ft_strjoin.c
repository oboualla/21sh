/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:53:32 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/20 03:22:38 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*one_return(char *str, char *str2)
{
	if (str)
		return (ft_strdup(str));
	if (str2)
		return (ft_strdup(str2));
	return (NULL);
}

char	*ft_strjoin(char *str, char *str2)
{
	int			i;
	char		*fraiche;
	int			j;

	i = 0;
	j = 0;
	if (!str || !str2)
		return (one_return(str, str2));
	if (!(fraiche = (char *)ft_memalloc((ft_strlen(str)
						+ ft_strlen(str2) + 1) * sizeof(char))))
		return (NULL);
	if (fraiche)
	{
		while (str[i])
		{
			fraiche[i] = str[i];
			i++;
		}
		while (str2[j])
			fraiche[i++] = str2[j++];
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (0);
}
