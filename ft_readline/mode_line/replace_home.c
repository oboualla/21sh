/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:54:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:48 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static char	*get_user(char *ptr)
{
	char	user[100];
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	ft_bzero((void*)user, 100);
	while (ptr[j] && ft_isalnum(ptr[j]))
		j++;
	if (!ptr[j] || ptr[j] == '/' || ptr[j] == ' ')
	{
		while (i < j)
		{
			user[i] = ptr[i];
			i++;
		}
		return (ft_strdup(user));
	}
	return (NULL);
}

static int	condition_(char *ptr)
{
	if (ptr[1] && ptr[1] != ' ' && ptr[1] != '/')
		return (1);
	return (0);
}

static char	*get_change(char *line)
{
	char	change[100];
	size_t	i;

	i = 0;
	ft_bzero((void*)change, 100);
	while (line[i] && line[i] != ' ' && line[i] != '/')
	{
		change[i] = line[i];
		i++;
	}
	return (ft_strdup(change));
}

static int	get_newchaine(char **nchain, char *ptr)
{
	char *user;
	char *tmp;

	if (!(user = get_user(ptr + 1)))
	{
		ft_strdel(nchain);
		return (0);
	}
	tmp = *nchain;
	*nchain = ft_remplacer_str(*nchain, getenv("USER"), user);
	free(tmp);
	if (access(*nchain, F_OK) == -1)
	{
		ft_putstr_fd("21sh: no such user or named directory :", 2);
		ft_putendl_fd(user, 2);
		ft_strdel(nchain);
		free(user);
		return (0);
	}
	free(user);
	return (1);
}

int			replace_home(char **line, size_t i)
{
	char *ptr;
	char *change;
	char *newchaine;
	char *rest;

	if ((ptr = ft_strchr(&(*line)[i], '~')))
	{
		newchaine = ft_strdup(getenv("HOME"));
		if (condition_(ptr) && !(get_newchaine(&newchaine, ptr)))
			return (0);
		change = get_change(&(*line)[i]);
		rest = ft_strndup(*line, i);
		ptr = ft_remplacer_str(&(*line)[i], change, newchaine);
		free(*line);
		free(newchaine);
		free(change);
		if (!(*line = ft_strjoin(rest, ptr)))
			return (-1);
		free(rest);
		free(ptr);
	}
	return (1);
}
