/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:20:10 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/29 17:51:58 by oboualla         ###   ########.fr       */
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
	if (!(comp = ft_readline("dquote")))
		return (0);
	if (!*line)
	{
		*line = comp;
		*save_line(NULL) = NULL;
		ctrl_c(line);
		return (0);
	}
	tmp = comp;
	comp = ft_strjoin("\n", tmp);
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(tmp, comp);
	free(tmp);
	free(comp);
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
		if (((*line)[i] == '"' && ((*line)[i - 1] != '\\')) && (!(balance & 1) && !(balance & 2)))
			balance++;
		else if (((*line)[i] == '"' && (*line)[i - 1] != '\\') && (balance & 1))
			balance--;
		if (((*line)[i] == '\'' && (*line)[i - 1] != '\\') && (!(balance & 2) && !(balance & 1)))
			balance += 2;
		else if (((*line)[i] == '\'' &&
		(*line)[i - 1] != '\\') && (balance & 2))
			balance -= 2;
		i++;
	}
	if (balance > 0)
		if ((ft_quots(line)))
			quots(line);
	return (1);
}
