/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:09:26 by fbrekke           #+#    #+#             */
/*   Updated: 2019/05/01 01:03:26 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

char			ft_pars(char **str, const char *delim, char **wrd)
{
	/*
	char	*d;
	char	*ret;
	int		i;

	i = 0;
	ret = 0;
	ret = ft_strnew(1);
	d = ft_strnew(1);
	ret = 126;
	printf("%s\n", wrd[0]);
	free(wrd[0]);
	//ft_memdel(wrd[0]);
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
	printf("\n%d\n", i);
	wrd = ft_strnew(i);
	printf("%s\n",(*str - i));
	wrd = ft_strncpy(wrd, (*str - i) , i);
	*str += --i;
	*/
	char	ret;
	char	a;
	int 	i;

	i = 0;
	ret = 126;
	printf("%s\n", *wrd);
	if (!*str)
		return (NULL);
	printf("str = %s\n", *str);
	printf("delim = (%s)\n", delim);
	a = ft_strchr(delim, **str);
	printf("!!![%d]\n", a);
	while (*str && (a = ft_strchr(delim, **str)) != -1)
	{
		*str += 1;
		ret = a < ret ? a : ret;
	}
	if (!*str)
		return (NULL);
	while (*str && ft_strchr(delim, **str) == -1 && ++*str)
		i++;
	//*wrd = ft_strnew(i + 1);
	//ft_bzero(wrd, (i + 1));
	printf("%s\n", *wrd);
	*str = *str - i;
	ft_strncpy(&(*wrd), &(*str), 5);
	//printf("%s\n", *wrd);
	//printf("%s\n", *wrd);
	*str += --i;
	return (ret);
}
