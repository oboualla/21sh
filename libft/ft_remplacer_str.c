/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplacer_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:39:55 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/07 00:29:49 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remplacer_str(char *chn, char *change, char *nchn)
{
	char	*new;
	char	*ptr;
	int		i;
	size_t	size;
	int		e;

	e = 0;
	i = 0;
	if (!chn || !change || !nchn)
		return (NULL);
	size = (ft_strlen(chn) - ft_strlen(change)) + ft_strlen(nchn);
	if (!(new = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr = ft_strstr(chn, change);
	while (chn[i] != '\0' && &chn[i] != ptr)
		i++;
	ft_strncpy(new, chn, i);
	ft_strcat(new, nchn);
	while (chn[i + e] != '\0' && chn[i + e] == change[e])
		e++;
	ft_strcat(new, &chn[i + e]);
	return (new);
}
