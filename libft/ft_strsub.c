/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:57:38 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/17 22:06:21 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len1;

	if (s == NULL)
		return (0);
	i = 0;
	str = (char *)malloc(len + 1 - start);
	if (str == NULL)
		exit(EXIT_FAILURE);
	len1 = len - start;
	while (i < len1 && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
