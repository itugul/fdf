/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:05:58 by ehaggon           #+#    #+#             */
/*   Updated: 2019/05/01 04:36:13 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

char ft_fuck(const char *s, int c)
{
	char c2;
	int i;

	i = 0;
	c2 = (char)c;
	while (s[i] != c2)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	if (i == 0)
	{
		return (s[i]);
	}
	else
		return(s[i]);
}
