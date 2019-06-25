/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:32:02 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 00:45:05 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			read_map(int fd, t_map **map)
{
	char	*line;
	char	*tmp;
	int		*xyzh;
	int		nth[4];

	xyzh = (int *)malloc(sizeof(int) * 4);
	insert_var(xyzh, nth);
	while ((nth[2] = get_next_line(fd, &line)) > 0)
	{
		tmp = line;
		nth[0] = nth[1];
		nth[1] = ft_num_words(line, ' ');
		if (nth[0] != 0 && nth[1] != nth[0])
			return (ft_report("not valid map"));
		pars_line(map, &line, xyzh, nth);
		xyzh[0]++;
		xyzh[1] = 0;
		ft_strdel(&tmp);
	}
	nth[3] = xyzh[3];
	free(xyzh);
	if (nth[2] == -1)
		return (ft_report("read error"));
	return (nth[3]);
}

int			*pars_line(t_map **map, char **line, int *xyzh, int *n)
{
	char	d;
	char	*wrd;

	wrd = ft_strnew(1);
	while (*line != '\0' && ((d = ft_pars(line, " ,", &wrd)) != -1)
		&& (xyzh[1] < n[1]))
	{
		if (d == ',')
			(*map)->color = hex_to_int(wrd);
		else
		{
			xyzh[2] = ft_atoi(wrd);
			xyzh[3] = xyzh[3] < ft_abs(xyzh[2]) ? ft_abs(xyzh[2]) : xyzh[3];
			push(map, xyzh);
			if (xyzh[0] > 0)
				(*map)->up = getnth(*map, n[1]);
			xyzh[1]++;
		}
	}
	ft_strdel(&wrd);
	return (xyzh);
}

void		push(t_map **head, int *data)
{
	t_map	*tmp;

	if (!(tmp = (t_map*)malloc(sizeof(t_map))))
		return ;
	tmp->line_num = data[0];
	tmp->anim_x = 0;
	tmp->anim_y = 0;
	tmp->anim_z = 0;
	tmp->fin_x = data[0];
	tmp->fin_y = data[1];
	tmp->fin_z = data[2];
	tmp->color = DEF_COLOR;
	tmp->next = (*head);
	tmp->up = NULL;
	(*head) = tmp;
}

int			hex_to_int(const char *s)
{
	int		i;
	int		k;
	int		b;
	int		j;

	i = 0;
	k = 1;
	j = ft_strlen(s);
	while (j-- > 2)
	{
		if (47 < s[j] && s[j] < 58)
			b = s[j] - 48;
		else if (64 < s[j] && s[j] < 71)
			b = s[j] - 55;
		else if (s[j] == 'x' && s[j - 1] == '0')
			j = 0;
		i += b * k;
		k *= 16;
	}
	return (i);
}

t_map		*getnth(t_map *head, int n)
{
	int		i;

	i = 0;
	while (i < n && head)
	{
		head = head->next;
		i++;
	}
	return (head);
}
