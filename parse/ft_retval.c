/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:15:06 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/09 15:57:58 by kbahrar          ###   ########.fr       */
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
	int		j;
	char	*snum;
	int		fd;

	if (str[*i] != '&')
		return (-1000);
	(*i)++;
	if (str[*i] == ' ' || !str[*i])
		return (-500);
	j = (*i);
	if (str[j] == '-')
		j++;
	while (str[j] && str[j] != ' ')
	{
		if ((str[j] < '0' || str[j] > '9'))
			return (-1000);
		j++;
	}
	snum = ft_strsub(str, *i, j);
	fd = snum[0] == '-' ? -1 : ft_atoi(snum);
	*i = j;
	free(snum);
	return (fd);
}

char		*ret_file(char *str, int *i)
{
	int		j;
	char	*file;
	char	tmp;

	tmp = 'n';
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	j = *i;
	if (str[j] == '>' || str[j] == '<' || str[j] == '\0')
		return (NULL);
	while (str[j] && str[j] != '<' && str[j] != '>' && str[j] != ' ')
	{
		if ((str[j] == '"' || str[j] == '\'') && tmp != str[j])
		{
			tmp = str[j];
			(*i)++;
			while (str[j] && str[j + 1] != tmp)
				j++;
		}
		j++;
	}
	file = tmp == 'n' ? ft_strsub(str, *i, j) : ft_strsub(str, *i, j - 1);
	*i = j;
	return (file);
}
