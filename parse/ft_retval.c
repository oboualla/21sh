/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:15:06 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/27 17:33:19 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

int			ret_ffd(char *str, int i)
{
	if (str[i - 1] >= '0' && str[i - 1] <= '9' && str[i - 2] == ' ')
	{
		return (str[i - 1] - '0');
	}
	return (-1);
}

char		ret_link(char *str, int *i)
{
	if (str[*i] == '<' && str[(*i) + 1] == '<')
	{
		(*i) += 2;
		if (str[*i] == '&')
			return ('e');
		return ('H');
	}
	else if (str[*i] == '<')
	{
		(*i)++;
		return ('C');
	}
	else if (str[*i] == '>' && str[(*i) + 1] == '>')
	{
		*i = (*i) + 2;
		if (str[*i] == '&')
			(*i)++;
		return ('A');
	}
	else
	{
		(*i)++;
		return ('W');
	}
}

int			ret_fd(char *str, int *i)
{
	int		tot;
	int		j;
	char	*snum;
	int		fd;

	tot = 0;
	if (str[*i] != '&')
		return (-1000);
	(*i)++;
	j = (*i);
	while (str[j] && str[j] != ' ')
	{
		if (str[j] != '-' && (str[j] < '0' || str[j] > '9'))
			return (-1000);
		j++;
	}
	snum = ft_strsub(str, *i, j);
	if (snum[0] == '-' && !snum[1])
		fd = -1;
	else
		fd = ft_atoi(snum);
	*i = j;
	free(snum);
	return (fd);
}

char		*ret_file(char *str, int *i)
{
	int		j;
	char	*file;

	while (str[*i] && str[*i] == ' ')
		(*i)++;
	j = *i;
	if (str[j] == '>' || str[j] == '<' || str[j] == '\0')
		return (NULL);
	while (str[j] && str[j] != '<' && str[j] != '>' && str[j] != ' ')
		j++;
	file = ft_strsub(str, *i, j);
	*i = j;
	return (file);
}
