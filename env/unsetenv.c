/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:47:04 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:53 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void	free_elem(t_vars **vars)
{
	free((*vars)->nom);
	free((*vars)->valeur);
	free(*vars);
}

void	ft_del_elem(char *nom, t_vars **vars)
{
	t_vars	*tmp;
	t_vars	*pre;

	tmp = (*vars)->next;
	pre = *vars;
	if (ft_strcmp(pre->nom, nom) == 0)
	{
		*vars = tmp;
		free_elem(&pre);
	}
	else
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->nom, nom) == 0)
			{
				pre->next = tmp->next;
				free_elem(&tmp);
				return ;
			}
			tmp = tmp->next;
			pre = pre->next;
		}
	}
}

void	ft_unsetenv(char **args, t_vars **vars)
{
	int		i;

	i = 1;
	if (!vars || !*vars)
		return ;
	if (args[i] == NULL)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
	{
		while (args[i])
		{
			ft_del_elem(args[i], vars);
			i++;
		}
	}
}
