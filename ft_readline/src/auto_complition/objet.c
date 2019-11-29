/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:06:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:30:23 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

int		exit_prog(t_ac **ac)
{
	ft_strdel(&(*ac)->cmd);
	ft_strdel(&(*ac)->file);
	ft_strdel(&(*ac)->path);
	free_double(&(*ac)->files);
	ft_memdel((void**)ac);
	return (0);
}

int		ft_strcmp_index(char *file, char *cmp)
{
	size_t i;

	if (!file | !cmp)
		return (0);
	i = 0;
	while (file[i] && cmp[i] && (unsigned char)file[i] == (unsigned char)cmp[i])
		i++;
	return (i);
}

size_t	get_len(char **t_file)
{
	size_t i;
	size_t index;
	size_t to;

	if (!t_file)
		return (0);
	if (!t_file[1])
		return (ft_strlen(t_file[0]));
	to = 0;
	i = 0;
	to = ft_strcmp_index(t_file[i], t_file[1]);
	while (t_file[++i])
	{
		index = ft_strcmp_index(t_file[i], t_file[0]);
		if ((size_t)to > index)
			to = index;
	}
	return ((size_t)to);
}
