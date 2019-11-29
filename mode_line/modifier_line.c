/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:33:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:58:01 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static size_t	get_next_index(const char *cmd, size_t index)
{
	char c;

	c = cmd[index++];
	while (cmd[index])
	{
		if (cmd[index] == c && cmd[index - 1] != '\\')
			break ;
		index++;
	}
	return (index);
}

int				modifier_line(t_vars *lst, char **line)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!*line)
		return (0);
	ptr = *line;
	while (ptr[i])
	{
		if ((ptr[i] == '"' || ptr[i] == '\'') && (!i || ptr[i - 1] != '\\'))
			i = get_next_index(ptr, i);
		else if (ptr[i] == '~' && (!i || ptr[i - 1] == ' '))
		{
			if (replace_home(&ptr, i) == -1)
				return (-1);
		}
		else if (ptr[i] == '$' && (!i || ptr[i - 1] != '\\'))
		{
			if (replace_var(lst, &ptr, i) == -1)
				return (-1);
		}
		i++;
	}
	*line = ptr;
	return (1);
}
