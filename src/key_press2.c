/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:35:28 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 01:18:24 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_press125(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->indent_x -= 10;
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press123(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->indent_y += 10;
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press124(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->indent_y -= 10;
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press88(void **param)
{
	x_rot(param[2], 1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press86(void **param)
{
	x_rot(param[2], -1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}
