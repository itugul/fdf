/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:13:46 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:30:42 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	ptr1 = dest;
	ptr2 = (char *)src;
	i = -1;
	while (++i < n)
		*(ptr1 + i) = *(ptr2 + i);
	return (dest);
}
