/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:47:05 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/23 18:40:15 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*trim;
	char	*ret;
	int		i;

	if (!str)
		return (ft_strdup("\0"));
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (ft_strdup("\0"));
	trim = ft_strdup(str + i);
	i = ft_strlen(trim) - 1;
	while (trim[i] == ' ' || trim[i] == '\t' || trim[i] == '\n')
		i--;
	trim[i + 1] = '\0';
	ret = ft_strdup(trim);
	free(trim);
	return (ret);
}
