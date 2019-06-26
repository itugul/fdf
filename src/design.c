/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:35:36 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 03:57:39 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_dda(void **param, t_map *map, t_map *end)
{
	int		step;
	int		i;
	float	x[3];
	float	y[3];

	if (((t_glob **)param)[3]->iso_flag == 1)
	{
		x[0] = map->anim_y + ((t_glob **)param)[3]->indent_y;
		x[1] = end->anim_y + ((t_glob **)param)[3]->indent_y;
		y[0] = map->anim_x + ((t_glob **)param)[3]->indent_x;
		y[1] = end->anim_x + ((t_glob **)param)[3]->indent_x;
	}
	else
	{
		insert_coord(x, y, param, map);
		insert_coord2(x, y, param, end);
	}
	step = count_step(x, y);
	i = -1;
	while (++i < step)
	{
		mlx_pixel_put(param[0], param[1], x[0], y[0],
			get_color(*map, param[3], *end));
		depression(x, y);
	}
}

void		iso(t_map *tmp, t_glob *glob)
{
	while (tmp != NULL)
	{
		if (glob->anim_flag == 0)
		{
			tmp->anim_z = glob->scale > glob->scale_old ?
				tmp->anim_z + tmp->anim_z / glob->scale_old :
					tmp->anim_z - tmp->anim_z / glob->scale_old;
		}
		else
		{
			tmp->anim_z != (tmp->fin_z * glob->scale) &&
				tmp->fin_z > 0 ? tmp->anim_z++ : 0;
			tmp->anim_z != (tmp->fin_z * glob->scale) &&
				tmp->fin_z < 0 ? tmp->anim_z-- : 0;
		}
		tmp->anim_x = ((tmp->fin_x * glob->scale) -
			(tmp->fin_y * glob->scale)) * cos(0.523599);
		tmp->anim_y = -tmp->anim_z + ((tmp->fin_x * glob->scale) +
			(tmp->fin_y * glob->scale)) * sin(0.523599);
		tmp = tmp->next;
	}
}

void		draw_map(void **param)
{
	t_map	*map;

	map = param[2];
	while (map->next != NULL)
	{
		if (map->line_num == map->next->line_num)
		{
			draw_dda(param, map, map->next);
			if (map->up)
				draw_dda(param, map, map->up);
		}
		else
			draw_dda(param, map, map->up);
		map = map->next;
	}
	menu(param);
}

int			animacion(void **param)
{
	t_glob	*glob;

	glob = param[3];
	if (glob->h_a <= glob->h)
	{
		glob->anim_flag = 1;
		iso(param[2], param[3]);
		z_rot(param[2], -10);
		mlx_clear_window(param[0], param[1]);
		draw_map(param);
		glob->h_a++;
	}
	else
	{
		glob->anim_flag = 0;
		mlx_clear_window(param[0], param[1]);
		draw_map(param);
	}
	return (0);
}

void		scaling(t_map *tmp, t_glob *glob)
{
	int		h[2];
	int		w[2];
	int		s;
	float	xy[2];

	h[0] = 0;
	h[1] = 0;
	w[0] = 0;
	w[1] = 0;
	while (tmp != NULL)
	{
		xy[0] = ((tmp->fin_x * glob->scale) - (tmp->fin_y * glob->scale)) *
			cos(0.523599);
		xy[1] = -(tmp->fin_z * glob->scale) + ((tmp->fin_x * glob->scale) +
			(tmp->fin_y * glob->scale)) * sin(0.523599);
		h[0] = h[0] > xy[0] ? xy[0] : h[0];
		h[1] = h[1] < xy[0] ? xy[0] : h[1];
		w[0] = w[0] < xy[1] ? xy[1] : w[0];
		w[1] = w[1] < xy[1] ? xy[1] : w[1];
		tmp = tmp->next;
	}
	s = h[1] - h[0] > w[1] - w[0] ? h[1] - h[0] : w[1] - w[0];
	printf("s == %d\n", s);
	glob->scale = 1300 / s >= 1 ? glob->scale * (1300 / s) : glob->scale;
}
