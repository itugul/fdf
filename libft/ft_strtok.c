/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:09:26 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/25 12:50:31 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtok(char *str, const char *delim)
{
	static char	*next;

	if (str)
	{
		next = str;
		while (*next && ft_chrstr(delim, *next))
			*next++ = '\0';
	}
	if (!*next)
		return (NULL);
	str = next;
	while (*next && !ft_chrstr(delim, *next))
		++next;
	while (*next && ft_chrstr(delim, *next))
		*next++ = '\0';
	return (str);
}
