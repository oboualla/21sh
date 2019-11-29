/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readpath2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:32:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/27 17:22:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

static int	access_file(char *file, char *path, t_ushort mode)
{
	char	pfile[1000];
	t_stat	st;

	ft_strcpy(pfile, path);
	ft_strcat(pfile, "/");
	ft_strcat(pfile, file);
	if (mode == ONLY_DIR)
	{
		if (!stat(pfile, &st) && S_ISDIR(st.st_mode))
			return (1);
	}
	else if (mode == ONLY_CMD)
	{
		if (!access(pfile, F_OK | X_OK))
			return (1);
	}
	else
		return (1);
	return (0);
}

static void	change_dname(char *d_name)
{
	char	*rest;
	size_t	i;

	if (!(i = ft_strchr_index(d_name, ' ')))
		return ;
	rest = ft_strdup(&d_name[i]);
	d_name[i] = '\\';
	d_name[i + 1] = '\0';
	ft_strcat(d_name, rest);
	ft_strdel(&rest);
	if ((i = ft_strchr_index(d_name, ' ')))
		change_dname(d_name);
}

static int	condition_(char *d_name, char *file, char *path, t_ushort mode)
{
	int		ret;

	ret = 1;
	if (!ft_strcmp(d_name, "..") && !ft_strcmp(d_name, "."))
		ret = 0;
	else if (ft_strncmp(d_name, file, ft_strlen(file)))
		ret = 0;
	else if (!access_file(d_name, path, mode))
		ret = 0;
	else if (ft_strchr(d_name, ' '))
		change_dname(d_name);
	else if (d_name[0] == '.' && (!file || file[0] != '.'))
		ret = 0;
	return (ret);
}

char		*get_file(char *file, char *path, size_t *len, t_ushort mode)
{
	DIR			*dirp;
	t_dirent	*drnt;
	char		*str[2];

	str[0] = NULL;
	if (!(dirp = opendir(path)))
		return (NULL);
	while ((drnt = readdir(dirp)))
		if (condition_(drnt->d_name, file, path, mode))
		{
			if (*len < ft_strlen(drnt->d_name))
				*len = ft_strlen(drnt->d_name);
			str[1] = str[0];
			str[0] = ft_strjoin(str[1], ":");
			ft_strdel(&str[1]);
			str[1] = str[0];
			str[0] = ft_strjoin(str[1], drnt->d_name);
			ft_strdel(&str[1]);
		}
	closedir(dirp);
	return (str[0]);
}
