/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:44:37 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/28 21:53:24 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_hist			*make_node(char *line)
{
	t_hist	*new;

	if (!(new = (t_hist*)ft_memalloc(sizeof(t_hist))))
		return (NULL);
	new->line = line;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

void			init_hist(t_hist **lst)
{
	t_hist	*tmp;
	t_hist	*rest;
	char	*line;
	int		fd;

	rest = NULL;
	line = ft_strjoin(getenv("HOME"), "/.21sh_history");
	if ((fd = open(line, O_RDONLY)) == -1)
	{
		free(line);
		return ;
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line, "$>:") > 0)
	{
		if (!(tmp = make_node(line)))
			return ;
		tmp->next = rest;
		if (rest)
			rest->back = tmp;
		rest = tmp;
	}
	*lst = rest;
	close(fd);
}

void			print_history(char *line, int fd)
{
	size_t i;

	i = 0;
	ft_putstr_fd("$>:", fd);
	while (line[i])
	{
		if (line[i] == '\n')
			ft_putchar_fd('\\', fd);
		ft_putchar_fd(*line, fd);
		i++;
	}
}

void			stock_hist(t_hist **lst)
{
	int		fd;
	char	*file;
	t_hist	*tmp;

	file = ft_strjoin(getenv("HOME"), "/.21sh_history");
	if ((fd = open(file, O_WRONLY | O_CREAT, S_IRWXU)) == -1)
	{
		free(file);
		return ;
	}
	free(file);
	if (*lst && (*lst)->next)
		while ((*lst)->next)
			(*lst) = (*lst)->next;
	while (*lst)
	{
		tmp = (*lst)->back;
		//ft_putendl_fd((*lst)->line, fd);
		print_history((*lst)->line, fd22);
		ft_strdel(&(*lst)->line);
		ft_memdel((void**)lst);
		*lst = tmp;
	}
	close(fd);
}

void			add_hist(char *line, t_hist **lst)
{
	t_hist *tmp;

	if (*lst && (*lst)->back)
	{
		while ((*lst)->back->back)
			*lst = (*lst)->back;
		ft_strdel(&(*lst)->back->line);
		ft_memdel((void**)&(*lst)->back);
	}
	tmp = *lst;
	if (!(*lst = make_node(line)))
		*lst = tmp;
	else if (tmp)
	{
		(*lst)->next = tmp;
		tmp->back = *lst;
	}
}
