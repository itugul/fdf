/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:18:57 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:33:31 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	int		res;

	if (*needle == '\0')
		return (char *)(haystack);
	len = ft_strlen(needle);
	while (*haystack)
	{
		if ((res = ft_strncmp(haystack, needle, len)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
