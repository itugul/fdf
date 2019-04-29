/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:59:33 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:29:50 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	n_cpy;

	len = ft_bit_depth(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy *= -1;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		s[--len] = n_cpy % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
