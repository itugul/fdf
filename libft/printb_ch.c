/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printb_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:52:47 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/11 13:02:04 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				printb_ch(unsigned char octet)
{
	int				i;
	unsigned char	c;

	i = 128;
	while (i > 0)
	{
		if (octet < i)
		{
			c = '0';
			write(1, &c, 1);
			i /= 2;
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - i;
			i /= 2;
		}
	}
	ft_putendl("");
}
