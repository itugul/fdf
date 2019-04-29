/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:37:01 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:33:24 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;

	j = (int)ft_strlen(s) + 1;
	while (j--)
		if (*(s + j) == (char)c)
			return ((char *)s + j);
	return (NULL);
}
