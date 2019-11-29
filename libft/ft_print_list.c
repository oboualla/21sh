/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printList.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:10:19 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/15 18:40:10 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr((char*)list->content);
		ft_putchar('\n');
		ft_putnbr((int)list->content_size);
		ft_putstr("\n\n");
		list = list->next;
	}
}
