/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:26:24 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 22:33:19 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

static int	add_builtins(char *file, char **files)
{
	char *tmp;

	if (!ft_strncmp(file, "setenv", ft_strlen(file)))
	{
		tmp = *files;
		*files = ft_strjoin(tmp, ":setenv");
		ft_strdel(&tmp);
	}
	else if (!ft_strncmp(file, "unsetenv", ft_strlen(file)))
	{
		tmp = ft_strjoin(*files, ":unsetenv");
		ft_strdel(files);
		*files = tmp;
	}
	return (1);
}

static char	**get_tabfile2(char *file, char **path, size_t *len)
{
	char		*str[2];
	char		**t_file;
	char		*tmp;
	size_t		i;

	i = 0;
	str[0] = NULL;
	while (path[i])
	{
		str[1] = get_file(file, path[i], len, ONLY_CMD);
		tmp = str[0];
		str[0] = ft_strjoin(str[0], str[1]);
		ft_strdel(&str[1]);
		ft_strdel(&tmp);
		ft_strdel(&path[i++]);
	}
	free(path);
	add_builtins(file, &str[0]);
	t_file = ft_strsplit(str[0], ':');
	ft_strdel(&str[0]);
	return (t_file);
}

static char	**get_tabfile1(t_ac *ac, size_t *len)
{
	char		*str[2];
	char		**t_file;

	str[0] = NULL;
	if (ft_strcmp(ac->cmd, "cd"))
		str[0] = get_file(ac->file, ac->path, len, ONLY_DIR | ONLY_CMD);
	else
		str[0] = get_file(ac->file, ac->path, len, ONLY_DIR);
	t_file = ft_strsplit(str[0], ':');
	ft_strdel(&str[0]);
	return (t_file);
}

int			get_lfile(t_ac *ac, size_t *len)
{
	char	**path;

	if (ac->file && ac->file[0] != '.' && !ft_strcmp(ac->cmd, ac->file))
	{
		if (!(path = ft_strsplit(getenv("PATH"), ':')))
			return (0);
		ac->files = get_tabfile2(ac->file, path, len);
	}
	else
		ac->files = get_tabfile1(ac, len);
	if (!(ac->files))
		return (0);
	return (1);
}
