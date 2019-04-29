/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:37:24 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:30:50 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdst;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	psrc = (char *)src;
	pdst = (char *)dest;
	if (psrc < pdst)
		while ((int)(--n) >= 0)
			*(pdst + n) = *(psrc + n);
	else
		while (++i < n)
			*(pdst + i) = *(psrc + i);
	return (dest);
}
