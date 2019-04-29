/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:13:46 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:32:00 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;

	i = (int)ft_strlen(s) + 1;
	j = -1;
	while (++j < i)
		if (*(s + j) == (char)c)
			return ((char *)s + j);
	return (NULL);
}
