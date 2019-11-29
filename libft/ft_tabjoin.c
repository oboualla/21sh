/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:00:52 by kbahrar           #+#    #+#             */
/*   Updated: 2019/09/14 20:03:55 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(char **tab1, char **tab2)
{
	int	tot;
	int	i;

	tot = 0;
	i = 0;
	while (tab1[i++])
		tot++;
	i = 0;
	while (tab2[i++])
		tot++;
	return (tot);
}

char		**ft_tabjoin(char **tab1, char **tab2, int place)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(char*) * (size(tab1, tab2) + 1 - place));
	while (tab1[i])
		tab[j++] = ft_strdup(tab1[i++]);
	while (tab2[place])
		tab[j++] = ft_strdup(tab2[place++]);
	tab[j] = NULL;
	return (tab);
}
