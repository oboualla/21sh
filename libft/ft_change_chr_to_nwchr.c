/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_chr_to_nwchr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:46:47 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/27 09:08:48 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_change_chr_to_nwchr(char *chaine, char chr, char nwchr)
{
	int i;

	i = 0;
	if (!chaine)
		return (0);
	while (chaine[i] != '\0')
	{
		if (chaine[i] == chr)
			chaine[i] = nwchr;
		i++;
	}
	return (1);
}
