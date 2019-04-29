/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printb_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:48:07 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/11 12:59:00 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printb_64(u_int64_t d)
{
	int	c;
	int	k;

	ft_putnbr(d);
	ft_putstr(" in binary number system is:\n");
	c = 63;
	while (c >= 0)
	{
		k = d >> c;
		if (k & 1)
			ft_putstr("1");
		else
			ft_putstr("0");
		if (c % 16 == 0)
			ft_putstr("\n");
		c--;
	}
	ft_putstr("\n");
}
