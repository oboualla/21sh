/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:38:18 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/27 17:08:28 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

void	couleur(char *file, char *path)
{
	char	join[1000];
	t_stat	st;

	ft_strcpy(join, path);
	ft_strcat(join, "/");
	ft_strcat(join, file);
	if (lstat(join, &st) == -1)
		ft_putstr("\033[0m");
	else if (S_ISDIR(st.st_mode))
		ft_putstr("\033[1;36m");
	else if (S_ISLNK(st.st_mode))
		ft_putstr("\033[1;35m");
	else if (S_ISBLK(st.st_mode))
		ft_putstr("\033[0;34m");
	else if (S_ISFIFO(st.st_mode))
		ft_putstr("\033[0;33m");
	else if (S_ISCHR(st.st_mode))
		ft_putstr("\033[1;34m");
	else
		ft_putstr("\033[0m");
}
