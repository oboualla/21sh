/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:03:56 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:30 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void			show_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

static int		error_hand(int flag)
{
	if (flag == 0)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (flag == 1)
		ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
	else
	{
		ft_putstr_fd("setenv: Variable name must ", 2);
		ft_putendl_fd("contain alphanumeric characters.", 2);
	}
	return (-1);
}

static int		checking(char **args)
{
	int		i;
	int		check;

	i = 1;
	check = 0;
	while (args[i++])
		check++;
	i = 0;
	if (check > 2)
		return (error_hand(0));
	else if (ft_isalpha(args[1][0]) == 0)
		return (error_hand(1));
	else
	{
		while (args[1][i])
		{
			if (ft_isalnum(args[1][i]) == 0)
				return (error_hand(3));
			i++;
		}
		return (1);
	}
}

static t_vars	*new_var(char *nom, char *value)
{
	t_vars *new;

	if (!(new = (t_vars*)ft_memalloc(sizeof(t_vars))))
		return (NULL);
	new->nom = ft_strdup(nom);
	if (value)
		new->valeur = ft_strdup(value);
	return (new);
}

void			ft_setenv(char **args, t_vars **vars)
{
	t_vars	*tmp;

	tmp = *vars;
	if (checking(args) < 0)
		return ;
	if (!*vars)
		*vars = new_var(args[1], args[2]);
	else
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->nom, args[1]))
			{
				ft_strdel(&tmp->valeur);
				if (args[2])
					tmp->valeur = ft_strdup(args[2]);
				return ;
			}
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp->next = new_var(args[1], args[2]);
	}
}
