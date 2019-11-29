/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:49:14 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 16:54:52 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

char			*ft_getenv(t_vars *lst, char *nom)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!ft_strcmp(lst->nom, nom))
			return (ft_strdup(lst->valeur));
		lst = lst->next;
	}
	return (NULL);
}

static char		*make_nom(char *str)
{
	char	*nom;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	if (!(nom = (char*)malloc(sizeof(char) * i + 1)))
		exit(EXIT_FAILURE);
	i = 0;
	while (str[i] != '=')
	{
		nom[i] = str[i];
		i++;
	}
	nom[i] = '\0';
	return (nom);
}

static char		*make_val(char *str)
{
	char	*val;
	int		i;
	int		j;
	int		t;

	i = 0;
	t = 0;
	while (str[i] != '=')
		i++;
	j = i + 1;
	while (str[i++])
		t++;
	if (!(val = (char*)malloc(sizeof(char) * t)))
		exit(EXIT_FAILURE);
	i = 0;
	while (str[j])
		val[i++] = str[j++];
	val[i] = '\0';
	return (val);
}

static t_vars	*init_vars(char **env)
{
	t_vars	*vars;

	if (!(vars = (t_vars*)malloc(sizeof(t_vars))))
		exit(EXIT_FAILURE);
	vars->nom = make_nom(env[0]);
	vars->valeur = make_val(env[0]);
	vars->next = NULL;
	return (vars);
}

t_vars			*ft_vars(char **env)
{
	int		i;
	t_vars	*vars;
	t_vars	*head;

	if (!env)
		return (NULL);
	i = 1;
	head = init_vars(env);
	vars = head;
	while (env[i])
	{
		vars->next = (t_vars*)malloc(sizeof(t_vars));
		vars = vars->next;
		vars->nom = make_nom(env[i]);
		vars->valeur = make_val(env[i]);
		i++;
	}
	vars->next = NULL;
	return (head);
}
