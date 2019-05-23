/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:05:58 by ehaggon           #+#    #+#             */
/*   Updated: 2019/04/30 23:04:17 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

int ft_strchr(const char *s, int c)
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
	printf("%d\n", i);
	if (i == 0)
	{
		printf("s[i] = %d\n", s[i]);
		return (s[i]);
	}
	else
		return(s[i - 1]);
}
