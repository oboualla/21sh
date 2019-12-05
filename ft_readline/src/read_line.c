/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 03:35:04 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/05 03:34:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static void		add_inside_line(char line[], char buff[], t_readl rd)
{
	char *rest;

	ft_change_chr_to_nwchr(buff, "\n\t", ' ');
	rest = ft_strdup(&line[rd.curpos]);
	ft_bzero((void*)&line[rd.curpos], (ft_strlen(line) - rd.curpos));
	ft_strcpy(&line[rd.curpos], buff);
	ft_strcat(line, rest);
	free(rest);
}

static int		check_buff(t_objet *objet, char *buff)
{
	t_curpos	curpos;
	size_t		index;
	size_t		newlen;

	newlen = ft_strlen(buff) + ft_strlen(objet->line);
	if (newlen >= LINE_SIZE)
		return (0);
	index = objet->rd.curpos;
	objet->rd.curpos = newlen;
	curpos = get_curpos(objet->line, objet->rd);
	objet->rd.curpos = index;
	if (curpos.y >= objet->rd.ws_row)
	{
		add_inside_line(objet->line, buff, objet->rd);
		return (0);
	}
	return (1);
}

static int		take_key(char buff[], t_objet *objet, t_capab *tc, t_hist **lst)
{
	unsigned int cast;

	cast = *(unsigned int*)buff;
	if (ft_isprint(buff[0]))
	{
		if (!check_buff(objet, buff))
			return (1);
		add_inside_line(objet->line, buff, objet->rd);
		l_print(objet->line, &objet->rd, tc, ft_strlen(buff));
	}
	else if (cast == '\t')
		auto_c(objet);
	else if (cast == 4 && !objet->line[0])
		return (0);
	else if (cast == ALT_C)
		alt_c(objet);
	else if (cast == ALT_X)
		alt_x(objet);
	else if (cast == ALT_V)
		alt_v(objet);
	arrow_key(objet, lst, cast);
	other_key(objet, cast);
	alt_key(objet, cast);
	return (1);
}

t_objet			**save_objet(t_objet *objet)
{
	static t_objet *save_obj;

	if (!save_obj)
		save_obj = objet;
	return (&save_obj);
}

char			*ft_readline(const char *prompt)
{
	t_objet		*objet;
	char		buff[READ_SIZE];
	t_termios	bckp;
	t_hist		*lst;

	lst = NULL;
	if (init_program(&lst, &bckp, &objet, prompt) == -1)
	{
		ft_putendl_fd("failure to initialiser termcap", 2);
		return (NULL);
	}
	save_objet(objet);
	ft_putendl(prompt);
	ft_putstr("$> ");
	ft_bzero((void*)buff, READ_SIZE);
	while (buff[0] != '\n')
	{
		ft_bzero((void*)buff, READ_SIZE);
		if (read(0, buff, READ_SIZE) < 0)
			return (exit_readline(&objet, &lst, 0));
		if (!(take_key(buff, objet, objet->tc, &lst)))
			return (exit_readline(&objet, &lst, 0));
	}
	tcsetattr(0, TCSANOW, &bckp);
	return (exit_readline(&objet, &lst, 1));
}
