/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:48:47 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 17:27:48 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static int	free_alloc_firstcmd(t_hist **lst, char *line, t_ushort func)
{
	if (func == 1)
	{
		if ((*lst)->back && (*lst)->next)
			*lst = (*lst)->next;
		else if (!(*lst)->back)
		{
			(*lst)->back = make_node(ft_strdup(line));
			(*lst)->back->next = (*lst);
		}
		else
		{
			ft_putstr(tgetstr("bl", NULL));
			return (0);
		}
	}
	else if (!(*lst)->back)
	{
		(*lst) = (*lst)->next;
		ft_strdel(&(*lst)->back->line);
		ft_memdel((void**)&(*lst)->back);
	}
	return (1);
}

void		kp(t_hist **lst, t_objet *obj)
{
	if ((*lst))
	{
		if (!(free_alloc_firstcmd(lst, obj->line, 1)))
			return ;
		hm(obj);
		ft_putstr(tgetstr("cd", NULL));
		ft_bzero((void*)obj->line, 1024);
		ft_strcpy(obj->line, (*lst)->line);
		if (obj->line[0] != '\0')
		{
			bs_print(obj->line, obj->rd, obj->tc);
			ed(obj);
		}
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

void		kd(t_hist **lst, t_objet *obj)
{
	if ((*lst) && (*lst)->back)
	{
		*lst = (*lst)->back;
		hm(obj);
		ft_putstr(tgetstr("cd", NULL));
		ft_bzero((void*)obj->line, 1024);
		ft_strcpy(obj->line, (*lst)->line);
		if (obj->line[0] != '\0')
		{
			bs_print(obj->line, obj->rd, obj->tc);
			ed(obj);
		}
		free_alloc_firstcmd(lst, obj->line, 2);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}
