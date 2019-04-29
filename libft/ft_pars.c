/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:09:26 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/25 19:24:09 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_pars(char **str, const char *delim, char **wrd)
{
	char	*d;
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(1);
	d = ft_strnew(1);
	*ret = 126;
	ft_strdel(wrd);
	// printf("str = [%s]\n", *str);
	// printf("delim = [%s]\n", delim);
	if (!*str)
		return (NULL);
	while (*str && (d = ft_strchr(delim, **str)) && *d)
	{
		*str += 1;
		*ret = *d < *ret ? *d : *ret;
	}
	if (!*str)
		return (NULL);
	while (*str && !ft_strchr(delim, **str) && ++*str)
		i++;
	// printf("i = [%d]\n", i);
	*wrd = ft_strnew(i);
	*wrd = ft_strncpy(*wrd, *str - i, i);
	// printf("wrd = [%s]\n", *wrd);
	// ft_putendl("!");
	*str += --i;
	return (ret);
}
