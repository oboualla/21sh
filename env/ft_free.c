/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:23:23 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:15 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void		free_list(t_vars **vars)
{
	t_vars	*tmp;

	tmp = *vars;
	while (tmp)
	{
		*vars = (*vars)->next;
		if (tmp->nom)
			free(tmp->nom);
		if (tmp->valeur)
			free(tmp->valeur);
		if (tmp)
			free(tmp);
		tmp = *vars;
	}
}
