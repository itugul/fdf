/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:32:42 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:31:57 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int			i;
	int			j;

	i = -1;
	j = (int)ft_strlen(dest);
	while (*(src + ++i))
		*(dest + j++) = *(src + i);
	*(dest + j) = '\0';
	return (dest);
}
