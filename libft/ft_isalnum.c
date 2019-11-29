/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:00:23 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/02 14:51:05 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	if ((argument >= 'a' && argument <= 'z') ||
			(argument >= 'A' && argument <= 'Z'))
		return (1);
	else
		return (0);
}
