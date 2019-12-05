/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:23:23 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/05 13:48:23 by oboualla         ###   ########.fr       */
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
