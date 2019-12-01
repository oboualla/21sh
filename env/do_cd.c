/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:43:29 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:08 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static void	update_pwd(char *path, t_vars **vars, char *flag)
{
	t_vars	*tmp;

	tmp = *vars;
	while (tmp)
	{
		if (ft_strcmp(tmp->nom, flag) == 0)
		{
			free(tmp->valeur);
			tmp->valeur = ft_strdup(path);
			return ;
		}
		tmp = tmp->next;
	}
}

static void	cderror(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) != -1)
	{
		if (!S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd(path, 2);
			ft_putendl_fd(": Is not a Directory.", 2);
			return ;
		}
	}
	if (access(path, F_OK) == 0)
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": Permission denied.", 2);
	}
	else
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory.", 2);
	}
}

static char	*mod_path(char *path, char **env)
{
	int	i;

	i = 0;
	if (!path && env)
	{
		while (env[i])
		{
			if (ft_strstr(env[i], "HOME=") != NULL)
				path = ft_strchr(env[i], '/');
			i++;
		}
	}
	else if (env)
	{
		while (env[i])
		{
			if (ft_strstr(env[i], "OLDPWD=") != NULL)
				path = ft_strchr(env[i], '/');
			i++;
		}
	}
	return (path);
}

static int	check_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("cd: Too many arguments.\n", 2);
		return (-1);
	}
	return (0);
}

void		do_cd(char **args, char **env, t_vars **vars)
{
	char	*pwd;
	char	*path;

	if (check_args(args) == -1)
		return ;
	path = args[1];
	pwd = ft_strnew(4096);
	if (!path || (path[0] == '-' && path[1] == '\0'))
		path = mod_path(path, env);
	getcwd(pwd, 4096);
	if (!path || chdir(path) == -1)
	{
		if (!path)
			ft_putendl_fd(": No such file or directory.", 2);
		else
			cderror(path);
		free(pwd);
		return ;
	}
	update_pwd(pwd, vars, "OLDPWD");
	getcwd(pwd, 4096);
	update_pwd(pwd, vars, "PWD");
	free(pwd);
}
