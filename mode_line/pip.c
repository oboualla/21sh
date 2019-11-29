/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:39:53 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:58:13 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int	join_pipe(char **line, char *read)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(tmp, read);
	free(tmp);
	return (1);
}

static int	complet_pipe(char **line)
{
	char *read;
	char *tmp;

	save_line(line);
	read = ft_readline("pipe");
	tmp = read;
	if (!*line)
	{
		*line = read;
		*save_line(NULL) = NULL;
		ctrl_c(line);
		return (1);
	}
	read = ft_strtrim(tmp);
	free(tmp);
	if (!read || !read[0])
		complet_pipe(line);
	else
		join_pipe(line, read);
	ft_strdel(&read);
	*save_line(NULL) = NULL;
	return (1);
}

int			check_pipe(char **line)
{
	int src;

	if (!line || !*line)
		return (0);
	src = ft_strlen(*line);
	if ((*line)[src - 1] == '|')
		complet_pipe(line);
	return (1);
}
