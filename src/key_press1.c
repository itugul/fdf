/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:09:31 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 00:43:56 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int keycode, void **param)
{
	t_glob	*glob;

	glob = param[3];
	if (keycode == 78 && glob->scale > 5 && glob->anim_flag == 0)
		key_press78(param);
	else if (keycode == 69 && glob->anim_flag == 0)
		key_press69(param);
	else if (keycode == 126 && glob->anim_flag == 0)
		key_press126(param);
	else if (keycode == 125 && glob->anim_flag == 0)
		key_press125(param);
	else if (keycode == 123 && glob->anim_flag == 0)
		key_press123(param);
	else if (keycode == 124 && glob->anim_flag == 0)
		key_press124(param);
	else if (keycode == 88 && glob->anim_flag == 0)
		key_press88(param);
	else
		key_press2(keycode, param);
	return (0);
}

void		key_press2(int keycode, void **param)
{
	t_glob	*glob;

	glob = param[3];
	if (keycode == 86 && glob->anim_flag == 0)
		key_press86(param);
	else if (keycode == 91 && glob->anim_flag == 0)
		key_press91(param);
	else if (keycode == 84 && glob->anim_flag == 0)
		key_press84(param);
	else if (keycode == 89 && glob->anim_flag == 0)
		key_press89(param);
	else if (keycode == 83 && glob->anim_flag == 0)
		key_press83(param);
	else if (keycode == 53)
		exit(0);
}

void		key_press78(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->scale_old = glob->scale;
	glob->scale--;
	iso(param[2], param[3]);
	z_rot(param[2], -10);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press69(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->scale_old = glob->scale;
	glob->scale++;
	iso(param[2], param[3]);
	z_rot(param[2], -10);
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}

void		key_press126(void **param)
{
	t_glob	*glob;

	glob = param[3];
	glob->indent_x += 10;
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}
