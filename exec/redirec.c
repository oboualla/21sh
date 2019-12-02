/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:46:55 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/02 21:00:43 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

char		*ft_herdoc(t_redirec *red)
{
	char	*heredoc;
	char	*tmp;

	tmp = NULL;
	heredoc = NULL;
	while (red)
	{
		if (red->link == 'H')
		{
			tmp = ft_strjoin(heredoc, red->heredoc);
			ft_strdel(&red->heredoc);
			ft_strdel(&heredoc);
			heredoc = ft_strdup(tmp);
			free(tmp);
		}
		red = red->next;
	}
	return (heredoc);
}

static int	ft_openfile(t_redirec *red)
{
	int		fd;

	fd = -1;
	if (red->link == 'W')
		fd = open(red->file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IROTH);
	else if (red->link == 'A')
		fd = open(red->file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR
		| S_IWUSR | S_IRGRP | S_IROTH);
	else if (red->link == 'C')
		if ((fd = open(red->file, O_RDWR)) == -1)
			return (-1);
	if (red->fd == -500 && red->ffd == -1)
		dup2(fd, 2);
	if (red->link == 'C')
		dup2(fd, 0);
	else if (red->ffd != -1)
		dup2(fd, red->ffd);
	else if (red->link != 'H')
		dup2(fd, 1);
	if (fd != -1)
		close(fd);
	return (0);
}

static int	ft_rederror(char *err, char *name, int fd)
{
	ft_putstr_fd("21sh: ", 2);
	if (name)
		ft_putstr_fd(name, 2);
	if (fd != -1)
		ft_putnbr_fd(fd, 2);
	ft_putendl_fd(err, 2);
	return (-1);
}

int			ft_redirec(t_redirec *red)
{
	int		fd;

	fd = -1;
	while (red)
	{
		if (red->file == NULL)
		{
			if (red->ffd != -1)
				fd = red->ffd;
			else
				fd = 1;
			if (red->fd < 0)
				close(red->ffd);
			else if (dup2(red->fd, fd) == -1)
				return (ft_rederror(": Bad file descriptor.", NULL, red->fd));
		}
		else
		{
			if ((ft_openfile(red)) == -1)
				return (ft_rederror(": No such file or directory.",
				red->file, -1));
		}
		red = red->next;
	}
	return (0);
}
