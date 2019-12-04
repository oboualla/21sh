/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:45:33 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/04 01:11:41 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_vars	*get_lstvars(t_vars **lst)
{
	static t_vars **vars;

	if (!(vars))
		vars = lst;
	return (*vars);
}

void	ctrl_c(char **line)
{
	char	*tmp;
	t_vars	*lst;

	if (!*line)
		return ;
	lst = get_lstvars(NULL);
	tmp = *line;
	*line = ft_strtrim(tmp);
	free(tmp);
	quots(line);
	check_pipe(line);
	if (!*line || !(*line)[0])
		return ;
	return ;
}
