/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printb_16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:08:43 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/11 12:59:17 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printb_16(u_int16_t d)
{
	int	c;
	int	k;

	ft_putnbr(d);
	ft_putstr(" in binary number system is:\n");
	c = 15;
	while (c >= 0)
	{
		k = d >> c;
		if (k & 1)
			ft_putstr("1");
		else
			ft_putstr("0");
		c--;
	}
	ft_putstr("\n");
}
