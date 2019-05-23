/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:06:59 by ehaggon           #+#    #+#             */
/*   Updated: 2019/04/29 20:28:11 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
