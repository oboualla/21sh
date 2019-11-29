/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:25:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/10 09:37:19 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *li_eff;
	t_list *li;

	li_eff = *alst;
	while (li_eff)
	{
		li = li_eff->next;
		del(li_eff->content, li_eff->content_size);
		free(li_eff);
		li_eff = li;
	}
	*alst = NULL;
}
