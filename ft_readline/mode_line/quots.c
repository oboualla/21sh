/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:20:10 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 19:38:46 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

char		***save_line(char **line)
{
	static char **sav;

	if (line && *line)
		sav = line;
	return (&sav);
}

static int	ft_quots(char **line)
{
	char *comp;
	char *tmp;

	save_line(line);
	comp = ft_readline("dquote");
	if (!*line)
	{
		*line = comp;
		*save_line(NULL) = NULL;
		ctrl_c(line);
		return (0);
	}
	tmp = comp;
	comp = ft_strjoin("\n", tmp);
	ft_strdel(&tmp);
	tmp = *line;
	*line = ft_strjoin(tmp, comp);
	ft_strdel(&tmp);
	ft_strdel(&comp);
	*save_line(NULL) = NULL;
	return (1);
}

int			quots(char **line)
{
	size_t i;
	size_t balance;

	balance = 0;
	i = 0;
	if (!line || !*line)
		return (-1);
	while ((*line)[i])
	{
		if (((*line)[i] == '"' && (!i || (*line)[i - 1] != '\\'))
			&& !(balance & 2))
			balance = (balance > 0) ? 0 : 1;
		else if (((*line)[i] == '\'' && (!i || (*line)[i - 1] != '\\')
			&& !(balance & 1)))
			balance = (balance > 0) ? 0 : 2;
		i++;
	}
	if (balance > 0)
		if ((ft_quots(line)))
			quots(line);
	return (1);
}
