/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:14:31 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:59 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int	commandes2(char **env, char **args)
{
	if (ft_strcmp(args[0], "/usr/bin/env") == 0 ||
	ft_strcmp(args[0], "env") == 0)
		show_env(env);
	else if (ft_strcmp(args[0], "/bin/echo") == 0 ||
	ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strchr(args[0], '/') == NULL)
	{
		ft_putstr(args[0]);
		ft_putstr(": command not found.\n");
	}
	else
		return (0);
	return (1);
}

static int	commandes(char **env, char **args, t_vars **vars)
{
	if (ft_strcmp(args[0], "exit") == 0)
	{
		free_sh(env, args, vars);
		exit(0);
	}
	else if (ft_strcmp(args[0], "/usr/bin/cd") == 0 ||
	ft_strcmp(args[0], "cd") == 0)
		do_cd(args, env, vars);
	else if (ft_strcmp("setenv", args[0]) == 0)
	{
		if (args[1])
			ft_setenv(args, vars);
		else
			show_env(env);
	}
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		ft_unsetenv(args, vars);
	else if (commandes2(env, args) == 0)
		return (0);
	ft_retfd(0);
	return (1);
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
			while (wait(NULL) > 0)
				;
	}
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
	else
	{
		free_paths(cmd);
		free_paths(env);
		if (flag == -2)
			*prs = (*prs)->next;
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
		{
			cmd[0] = access_file(env, cmd[0]);
			if (commandes(env, cmd, vars) == 0)
				ft_exceve(prs, cmd, env, p0);
		}
		for_norm(-2, &prs, cmd, env);
	}
	ft_retfd(3);
}
