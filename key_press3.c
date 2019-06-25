/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:36:21 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/25 22:37:03 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_press91(void **param)
{
	y_rot(param[2], 1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press84(void **param)
{
	y_rot(param[2], -1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press89(void **param)
{
	z_rot(param[2], 1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press83(void **param)
{
	z_rot(param[2], -1);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}
