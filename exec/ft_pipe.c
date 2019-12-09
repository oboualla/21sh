/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:23:33 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/09 15:53:26 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

int			check_child(int status)
{
	if (WTERMSIG(status) == SIGSEGV)
		ft_putendl_fd("Segmentation fault", 2);
	else if (WTERMSIG(status) == SIGABRT)
		ft_putendl_fd("Aborted", 2);
	return (1);
}

void		ft_retfd(int flag)
{
	static int	stdin;
	static int	stdout;
	static int	stderr;

	if (flag == 1)
	{
		stdin = dup2(0, 167);
		stdout = dup2(1, 168);
		stderr = dup2(2, 169);
	}
	else if (flag == 2)
		dup2(stdout, 1);
	else
	{
		dup2(stdin, 0);
		dup2(stdout, 1);
		dup2(stderr, 2);
		if (flag == 3)
		{
			close(stdin);
			close(stdout);
			close(stderr);
		}
	}
}

int			ft_pipe(int flag)
{
	static int		fd[2];

	if (flag == -1)
	{
		if (pipe(fd) == -1)
			exit(1);
		dup2(fd[1], 1);
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

int			ft_pipehelp(t_parse *prs)
{
	static int	p0 = -1;
	static char	*heredoc = NULL;

	if (p0 == -1)
		heredoc = ft_herdoc(prs->red);
	if (p0 != -1)
		p0 = ft_pipe(p0);
	if (prs->link == 'p' || heredoc)
		p0 = ft_pipe(-1);
	if (heredoc != NULL)
	{
		ft_putstr(heredoc);
		free(heredoc);
		heredoc = NULL;
		ft_retfd(2);
		return (-2);
	}
	if (prs->red != NULL)
		if (ft_redirec(prs->red) == -1)
			return (-5);
	return (p0);
}
