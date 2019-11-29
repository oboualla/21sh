/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:37:31 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 14:01:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_count_size(unsigned int nb, int s)
{
	char	*str;
	int		size;

	size = 2;
	str = NULL;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	if (s == 1)
		str = (char*)malloc(sizeof(char) * size + 1);
	if (s == 0)
		str = (char*)malloc(sizeof(char) * size);
	if (str)
		return (str);
	return (NULL);
}

static char		*ft_convertir(char *str, unsigned int n, int s)
{
	int i;

	i = 0;
	if (n == 0)
	{
		str[0] = 0 + '0';
		i++;
	}
	else if (n > 0)
	{
		while (n > 0)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
			i++;
		}
		if (s == 1)
		{
			str[i] = '-';
			i++;
		}
	}
	str[i] = '\0';
	ft_rev(str);
	return (str);
}

char			*ft_itoa(int n)
{
	unsigned	int		nb;
	char				*str;
	int					s;

	s = 0;
	str = NULL;
	if (n < 0)
	{
		n = n * -1;
		s = 1;
	}
	nb = n;
	str = ft_count_size(nb, s);
	if (!(str))
		return (0);
	ft_convertir(str, nb, s);
	return (str);
}
