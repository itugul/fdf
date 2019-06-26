/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:26:48 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 04:00:05 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		insert_var(int *xyzh, int *n)
{
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	xyzh[0] = 0;
	xyzh[1] = 0;
	xyzh[2] = 0;
	xyzh[3] = 0;
}

void		insert_glob(t_glob *glob)
{
	glob->scale = 5.0;
	glob->scale_old = 5.0;
	glob->indent_x = 500;
	glob->indent_y = 900;
	glob->anim_flag = 0;
	glob->h = 0;
	glob->h_a = 0;
	glob->iso_flag = 1;
	glob->menu_flag = 0;
}

void		insert_param(void **param)
{
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 2500, 1300, "test");
}

int			count_step(float *x, float *y)
{
	int		step;

	step = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
	x[2] = (x[1] - x[0]) / step;
	y[2] = (y[1] - y[0]) / step;
	return (step);
}

void		insert_coord(float *x, float *y, void **param, t_map *map)
{
	x[0] = (map->y * ((t_glob **)param)[3]->scale) +
		((t_glob **)param)[3]->indent_y;
	y[0] = (map->x * ((t_glob **)param)[3]->scale) +
		((t_glob **)param)[3]->indent_x;
}
