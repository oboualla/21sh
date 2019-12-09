/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_chr_to_nwchr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:46:47 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 22:39:42 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_change_chr_to_nwchr(char *chaine, char *chr, char nwchr)
{
	size_t i;
	size_t j;

	i = 0;
	if (!chaine)
		return (0);
	while (chaine[i] != '\0')
	{
		j = 0;
		while (chr[j])
		{
			if ((chaine[i] == chr[j] ||
			!ft_isprint(chaine[i])) && chaine[i] != '\n')
			{
				chaine[i] = nwchr;
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}
