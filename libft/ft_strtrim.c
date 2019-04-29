/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:53:02 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/22 14:50:58 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blank(char *s, size_t j)
{
	size_t	i;

	i = 0;
	while ((*(s + i)) == ' ' || (*(s + i)) == '\t' || (*(s + i)) == '\n')
		i++;
	if (i >= j)
		return (0);
	return (1);
}

char		*ft_strtrim(char const *s)
{
	size_t	j;
	size_t	l;
	size_t	n[2];
	char	*rez;

	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	n[1] = blank((char *)s, j);
	if (n[1] == 0)
		return (ft_strdup(""));
	n[1] = 0;
	if (!(ft_whitesp((char *)s, &n[1], &j)))
		return ((char *)s);
	l = (n[1] == ft_strlen(s)) ? 0 : ft_strlen(s) - n[1] - \
				(ft_strlen(s) - j);
	rez = ft_strnew(l + 1);
	if (!rez)
		return (NULL);
	n[0] = 0;
	while (n[1] <= j)
		*(rez + n[0]++) = *(s + n[1]++);
	return (rez);
}
