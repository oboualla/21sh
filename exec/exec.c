/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:14:31 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/09 20:19:35 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int	commandes2(char **env, char **args)
{
	if (!ft_strcmp(args[0], "env"))
		show_env(env);
	else if (!ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else
	{
		args[0] = access_file(env, args[0]);
		if (!ft_strchr(args[0], '/'))
		{
			ft_putstr_fd(args[0], 2);
			ft_putendl_fd(" : commande not found", 2);
		}
		else
			return (0);
	}
	return (1);
}

static int	commandes(char **env, char **args, t_vars **vars)
{
	if (!ft_strcmp(args[0], "cd"))
		do_cd(args, env, vars);
	else if (!ft_strcmp("setenv", args[0]))
	{
		if (args[1])
			ft_setenv(args, vars);
		else
			show_env(env);
	}
	else if (!ft_strcmp(args[0], "unsetenv"))
		ft_unsetenv(args, vars);
	else if (commandes2(env, args) == 0)
		return (0);
	ft_retfd(0);
	return (1);
}

static void	for_norm(int flag, t_parse **prs, char **cmd, char **env)
{
	if (flag == 1)
	{
		while (*prs)
		{
			if ((*prs)->next && (*prs)->next->link != 'p')
			{
				(*prs) = (*prs)->next;
				break ;
			}
			(*prs) = (*prs)->next;
		}
	}
	else if (flag == -1 || flag == -2)
	{
		free_paths(cmd);
		free_paths(env);
		if (flag == -2)
			*prs = (*prs)->next;
	}
}

static void	ft_exceve(t_parse *prs, char **cmd, char **env, int p0)
{
	if (!fork())
	{
		if (p0 != -1)
			close(p0);
		if (execve(cmd[0], cmd, env) == -1)
		{
			ft_putstr_fd(cmd[0], 2);
			if (access(cmd[0], F_OK) == 0)
				ft_putstr_fd(": Permission denied.\n", 2);
			else
				ft_putstr_fd(": command not found.\n", 2);
			exit(1);
		}
	}
	else
	{
		ft_retfd(0);
		if (prs->link != 'p')
		{
			while (wait(&p0) > 0)
				;
			check_child(p0);
		}
	}
}

void		exec(t_parse *prs, t_vars **vars)
{
	char	**cmd;
	int		p0;
	char	**env;

	ft_retfd(1);
	while (prs)
	{
		modifier_line(*vars, &prs->cmd);
		cmd = make_param(prs->cmd);
		env = make_env(*vars);
		if ((p0 = ft_pipehelp(prs)) <= -2)
		{
			for_norm(-1, NULL, cmd, env);
			if (p0 == -5)
				for_norm(1, &prs, NULL, NULL);
			continue ;
		}
		if (cmd && cmd[0])
			if (!commandes(env, cmd, vars))
				ft_exceve(prs, cmd, env, p0);
		for_norm(-2, &prs, cmd, env);
	}
	ft_retfd(3);
}
