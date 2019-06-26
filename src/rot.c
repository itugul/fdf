/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:31:05 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 03:28:42 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rot(t_map *map, int sig)
{
	float	y;
	float	z;

	while (map != NULL)
	{
		y = map->anim_y;
		z = map->anim_z;
		map->anim_y = (y * cos(0.1 * sig)) + (z * sin(0.1 * sig));
		map->anim_z = (-y * sin(0.1 * sig)) + (z * cos(0.1 * sig));
		map = map->next;
	}
}

void	y_rot(t_map *map, int sig)
{
	float	x;
	float	z;

	while (map != NULL)
	{
		x = map->anim_x;
		z = map->anim_z;
		map->anim_x = (x * cos(0.1 * sig)) + (z * sin(0.1 * sig));
		map->anim_z = (-x * sin(0.1 * sig)) + (z * cos(0.1 * sig));
		map = map->next;
	}
}

void	z_rot(t_map *map, int sig)
{
	float	y;
	float	x;

	while (map != NULL)
	{
		y = map->anim_y;
		x = map->anim_x;
		map->anim_x = (x * cos(0.1 * sig)) - (y * sin(0.1 * sig));
		map->anim_y = (x * sin(0.1 * sig)) + (y * cos(0.1 * sig));
		map = map->next;
	}
}
