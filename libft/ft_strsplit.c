/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 00:01:01 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 22:39:17 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*ft_copyword(char *word, int n)
{
	char	*one_word;
	int		i;

	i = 0;
	if (!(word))
		return (NULL);
	if (!(one_word = ft_strnew(n - i)))
		return (NULL);
	while (word[i] != '\0' && i < n)
	{
		one_word[i] = word[i];
		i++;
	}
	one_word[i] = '\0';
	return (one_word);
}

static char		**ft_remplir(char **tab, char *s, char c)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	j = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			tab[j++] = ft_copyword(&s[i], ft_wordlen(s + i, c));
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		*src;

	src = (char *)s;
	if (!(src))
		return (0);
	if (!(tab = (char**)ft_memalloc(sizeof(char *)
				* (ft_count_word(src, c) + 1))))
		return (0);
	ft_remplir(tab, src, c);
	return (tab);
}
