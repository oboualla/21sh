/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:18:01 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/08 22:47:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		free_sh(char **env, char **args, t_vars **vars)
{
	if (env)
		free_paths(env);
	if (args)
		free_paths(args);
	if (vars)
		free_list(vars);
}

void		ft_freeall(char **line, char **read, t_parse *prs)
{
	t_redirec	*tmp;
	t_parse		*ptmp;

	ft_strdel(read);
	ft_strdel(line);
	while (prs)
	{
		ft_strdel(&prs->cmd);
		while (prs->red)
		{
			ft_strdel(&prs->red->file);
			tmp = prs->red;
			prs->red = prs->red->next;
			free(tmp);
		}
		ptmp = prs;
		prs = prs->next;
		free(ptmp);
		ptmp = NULL;
	}
}

static int	get_line(char **line)
{
	if (!(*line = ft_readline(prompt())))
		return (-1);
	if (!*line)
		return (0);
	return (1);
}

int			main(void)
{
	extern char		**environ;
	char			*line;
	t_parse			*prs;
	t_vars			*vars;

	vars = ft_vars(environ);
	get_lstvars(&vars);
	line = NULL;
	while (1)
	{
		if (get_line(&line) < 0 || !ft_strncmp(line, "exit", ft_strlen("exit")))
			break ;
		if (line)
		{
			prs = parse_line(line);
			exec(prs, &vars);
			ft_freeall(&line, NULL, prs);
		}
		ft_strdel(save_prompt(NULL));
	}
	ft_strdel(save_prompt(NULL));
	ft_strdel(&line);
	free_list(&vars);
	return (EXIT_SUCCESS);
}
