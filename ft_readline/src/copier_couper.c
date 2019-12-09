/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copier_couper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:15:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 22:29:43 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static void	move_right(t_objet *obj)
{
	if (obj->rd.curpos < ft_strlen(obj->line))
	{
		ft_putstr(obj->tc->clear_line);
		ft_putstr(tgetstr("us", NULL));
		if (obj->line[obj->rd.curpos] != '\n')
			ft_putchar(obj->line[obj->rd.curpos]);
		else
			to_next_line(obj->tc, 1);
		obj->rd.curpos++;
		ft_putstr(tgetstr("ue", NULL));
		bs_print(obj->line, obj->rd, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

static void	move_left(t_objet *obj, t_readl *rd)
{
	if (obj->rd.curpos > 0)
	{
		kl(obj);
		ft_putstr(obj->tc->clear_line);
		bs_print(obj->line, obj->rd, obj->tc);
		if (obj->rd.curpos < rd->curpos)
			rd->curpos = obj->rd.curpos;
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

static void	couper_line(t_objet *obj, t_readl *rd)
{
	t_curpos	curpos;
	t_curpos	newpos;
	char		*rest;

	curpos = get_curpos(obj->line, obj->rd);
	newpos = get_curpos(obj->line, *rd);
	obj->copier = ft_strndup(&obj->line[rd->curpos],
	(obj->rd.curpos - rd->curpos));
	rest = ft_strdup(&obj->line[obj->rd.curpos]);
	ft_bzero((void*)&obj->line[rd->curpos],
	(ft_strlen(obj->line) - rd->curpos));
	ft_strcat(obj->line, rest);
	free(rest);
	curs_newpos(curpos, newpos, obj->tc);
	ft_putstr(obj->tc->clear_line);
	obj->rd = *rd;
	bs_print(obj->line, obj->rd, obj->tc);
}

int			alt_c(t_objet *obj)
{
	char			buff[4];
	unsigned int	cast;
	t_readl			rd;

	ft_strdel(&obj->copier);
	rd = obj->rd;
	ft_bzero((void*)buff, 4);
	while (read(0, buff, 4) > 0)
	{
		cast = *(unsigned int*)buff;
		if (cast == ALT_C)
			break ;
		else if (cast == KR)
			move_right(obj);
		else if (cast == KL)
			move_left(obj, &rd);
		else
			return (0);
		ft_bzero((void*)buff, 4);
	}
	obj->copier = ft_strndup(&obj->line[rd.curpos],
	(obj->rd.curpos - rd.curpos));
	return (1);
}

int			alt_x(t_objet *obj)
{
	char			buff[4];
	unsigned int	cast;
	t_readl			rd;

	ft_strdel(&obj->copier);
	rd = obj->rd;
	ft_bzero((void*)buff, 4);
	while (read(0, buff, 4) > 0)
	{
		cast = *(unsigned int*)buff;
		if (cast == ALT_X)
			break ;
		else if (cast == KR)
			move_right(obj);
		else if (cast == KL)
			move_left(obj, &rd);
		else
			return (0);
		ft_bzero((void*)buff, 4);
	}
	couper_line(obj, &rd);
	return (1);
}
