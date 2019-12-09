/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:47:43 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 13:55:49 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int		ft_make_line(char **rest, char **line, char *sep)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!*rest)
		return (0);
	while ((*rest)[i] && sep[i] && (*rest)[i] == sep[i])
		i++;
	if (!(ptr = ft_strstr(&(*rest)[i], sep)))
	{
		*line = ft_strdup(&(*rest)[i]);
		ft_strdel(rest);
	}
	else
	{
		ptr[0] = '\0';
		*line = ft_strdup(&(*rest)[i]);
		i = 1;
		while (ptr[i] && sep[i] && ptr[i] == sep[i])
			i++;
		ptr = ft_strdup(&ptr[i]);
		ft_strdel(rest);
		*rest = ptr;
	}
	return (1);
}

static t_reste	*add_fd(const int fd)
{
	t_reste *new;

	if (!(new = (t_reste*)ft_memalloc(sizeof(t_reste))))
		return (NULL);
	new->fd = fd;
	if (!(new->reste = ft_strnew(0)))
		return (NULL);
	new->next = NULL;
	return (new);
}

static t_reste	*ft_check_fd(const int fd, t_reste **list)
{
	t_reste *tmp;
	t_reste *ptr;
	t_reste *new;

	if (!(*list))
	{
		new = add_fd(fd);
		*list = new;
	}
	else
	{
		ptr = *list;
		while (ptr)
		{
			if (ptr->fd == fd)
				return (ptr);
			tmp = ptr;
			ptr = ptr->next;
		}
		new = add_fd(fd);
		tmp->next = new;
	}
	return (new);
}

static int		ft_dellst(t_reste *name, t_reste **list)
{
	t_reste **ptr;
	t_reste *del;

	del = *list;
	if (del == name)
	{
		*list = del->next;
		ft_memdel((void*)&name);
		return (0);
	}
	while (del->next != name)
		del = del->next;
	ptr = &del->next;
	*ptr = name->next;
	ft_memdel((void*)&name);
	return (0);
}

int				get_next_line(const int fd, char **line, char *sep)
{
	static t_reste	*list;
	t_reste			*ptr_surn;
	char			*buff;
	char			*ptr;

	if (read(fd, NULL, 0) < 0 || !line || fd > 4096)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	ptr_surn = ft_check_fd(fd, &list);
	while (!ft_strstr(ptr_surn->reste, sep) &&
			(read(fd, buff, BUFF_SIZE)))
	{
		ptr = ptr_surn->reste;
		ptr_surn->reste = ft_strjoin(ptr, buff);
		ft_strdel(&ptr);
		ft_memset((void*)buff, 0, BUFF_SIZE);
		if (ft_strstr(ptr_surn->reste, sep) &&
			ft_strstr(ft_strstr(ptr_surn->reste, sep), sep))
			break ;
	}
	ft_strdel(&buff);
	if (!(ft_make_line(&ptr_surn->reste, &*line, sep)))
		return (ft_dellst(ptr_surn, &list));
	return (1);
}
