/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:30:40 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/28 19:39:43 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static int	get_keyval(char *line, t_vars *lst, char **key, char **val)
{
	size_t j;

	j = 0;
	while (line[++j])
		if (!ft_isalnum(line[j]) && line[j] != '_')
			break ;
	if (j == 1 && line[j] == '$')
		j++;
	*key = ft_strndup(line, j);
	if (!(*val = ft_getenv(lst, (*key) + 1)))
		if (ft_strcmp(*key, "$$") && ft_strcmp(*key, "$PPID"))
			*val = ft_strdup("\0");
	if (!*val && !ft_strcmp(*key, "$$"))
		*val = ft_itoa(getpid());
	else if (!*val)
		*val = ft_itoa(getppid());
	return (1);
}

int			replace_var(t_vars *lst, char **line, size_t i)
{
	char *key;
	char *value;
	char *tmp;

	if (!i || (*line)[i - 1] != '\\')
	{
		get_keyval(&(*line)[i], lst, &key, &value);
		tmp = ft_remplacer_str(&(*line)[i], key, value);
		free(key);
		free(value);
		key = ft_strndup(*line, i);
		free(*line);
		if (!(*line = ft_strjoin(key, tmp)))
			return (-1);
		free(key);
		free(tmp);
	}
	return (1);
}
