/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:24:27 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 00:43:17 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : (placement / distance));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_map start, t_glob *glob, t_map end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = percent(-glob->h, glob->h, start.fin_z);
	red = get_light((start.color >> 16) & 0xFF,
		(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
		(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		color_map(t_map *map, t_glob *glob)
{
	float	percentage;
	int		red;
	int		green;
	int		blue;

	while (map->next != NULL)
	{
		percentage = percent(-glob->h, glob->h, map->fin_z);
		if (map->color == DEF_COLOR)
			map->color = 16777215 * percentage;
		map = map->next;
	}
}
