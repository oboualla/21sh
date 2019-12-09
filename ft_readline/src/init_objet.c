/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:17:12 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 14:04:57 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static t_readl	init_readl(const char *prompt)
{
	t_readl		rl;
	t_winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	rl.ws_col = ws.ws_col;
	rl.ws_row = ws.ws_row;
	rl.prompt_len = ft_strlen(prompt);
	rl.curpos = 0;
	return (rl);
}

static char		*check_line(char *line, char *prompt, t_hist **lst)
{
	char *retline;

	retline = ft_strdup(line);
	if (retline && ft_strcmp(prompt, "dquote")
		&& ft_strcmp(prompt, "pipe")
		&& ft_strcmp(prompt, "heredoc"))
	{
		*save_objet(NULL) = NULL;
		ctrl_c(&retline);
		add_hist(ft_strdup(retline), lst);
		stock_hist(lst);
	}
	return (retline);
}

char			*exit_readline(t_objet **objet, t_hist **lst, int flag)
{
	char *line;

	if (!objet || !*objet)
		return (NULL);
	line = NULL;
	ed(*objet);
	ft_putchar('\n');
	ft_putstr(tgetstr("cd", NULL));
	if (flag == 1)
		line = check_line((*objet)->line, (*objet)->prompt, lst);
	*save_objet(NULL) = NULL;
	free_lsthist(lst);
	ft_memdel((void**)&(*objet)->tc);
	ft_memdel((void**)objet);
	return (line);
}

t_objet			*init_objet(const char *prompt)
{
	t_objet *objet;

	if (!(objet = (t_objet*)ft_memalloc(sizeof(t_objet))))
		return (NULL);
	ft_bzero((void*)objet->line, LINE_SIZE);
	objet->prompt = (char*)prompt;
	if (init_tc(&objet->tc) == -1)
	{
		ft_memdel((void**)&objet);
		return (NULL);
	}
	if (init_mode() == -1)
	{
		ft_memdel((void**)&objet);
		return (NULL);
	}
	objet->rd = init_readl("$> ");
	return (objet);
}

int				init_program(t_hist **lst, t_termios *bckp,
t_objet **objet, const char *prompt)
{
	init_sig();
	if (tcgetattr(0, bckp) == -1)
		return (-1);
	if (!(*objet = init_objet(prompt)))
		return (-1);
	init_hist(lst);
	save_objet(*objet);
	return (1);
}
