/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:58:02 by fbrekke           #+#    #+#             */
/*   Updated: 2019/02/19 19:05:17 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) *
		(ft_num_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_num_words(s, c))
	{
		k = 0;
		if (!(s2[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			return (s2 = ft_freefree(s2));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			s2[i][k++] = s[j++];
	}
	s2[i] = NULL;
	return (s2);
}
