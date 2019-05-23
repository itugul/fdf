/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:29:15 by ehaggon           #+#    #+#             */
/*   Updated: 2019/04/29 20:12:15 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

char	*ft_strnew(size_t size)
{
	char			*str;

	if (size == (size_t)-1)
		return (NULL);
	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
