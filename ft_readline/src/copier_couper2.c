/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copier_couper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:41:02 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 13:47:00 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

void	alt_v(t_objet *obj)
{
	char	*rest;

	if (obj->copier)
	{
		rest = ft_strdup(&obj->line[obj->rd.curpos]);
		ft_bzero((void*)&obj->line[obj->rd.curpos],
		(ft_strlen(obj->line) - obj->rd.curpos));
		ft_strcat(obj->line, obj->copier);
		ft_strcat(obj->line, rest);
		free(rest);
		ft_putstr(obj->tc->clear_line);
		bs_print(obj->line, obj->rd, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}
