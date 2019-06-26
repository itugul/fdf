/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:07:34 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 03:58:32 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_press4(void **param)
{
	((t_glob **)param)[3]->menu_flag =
		((t_glob **)param)[3]->menu_flag == 0 ? 1 : 0;
	mlx_clear_window(param[0], param[1]);
	draw_map(param);
}
