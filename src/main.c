/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:04:25 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 04:03:04 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu(void **param)
{
	if (((t_glob **)param)[3]->anim_flag == 1)
		mlx_string_put(param[0], param[1],
			25, 25, 0xFFFFFF, "Just relax and watch");
	else if (((t_glob **)param)[3]->menu_flag == 0)
		mlx_string_put(param[0], param[1],
			25, 25, 0xFFFFFF, "for help press \"h\"");
	else
	{
		mlx_string_put(param[0], param[1],
			25, 25, 0xFFFFFF, "for moving use arrows");
		mlx_string_put(param[0], param[1],
			25, 50, 0xFFFFFF, "for zoom use +/- on numpad");
		mlx_string_put(param[0], param[1],
			25, 75, 0xFFFFFF, "for projections change use 5");
		mlx_string_put(param[0], param[1],
			25, 100, 0xFFFFFF, "for rotation use 8/2/4/6/7/1");
		mlx_string_put(param[0], param[1],
			25, 125, 0xFFFFFF, "ESC is exit?");
		mlx_string_put(param[0], param[1],
			25, 175, 0xFFFFFF, "By Odin! By Thor! Use your brain!");
	}
}

void		insert_coord2(float *x, float *y, void **param, t_map *end)
{
	x[1] = (end->y * ((t_glob **)param)[3]->scale) +
		((t_glob **)param)[3]->indent_y;
	y[1] = (end->x * ((t_glob **)param)[3]->scale) +
		((t_glob **)param)[3]->indent_x;
}

void		depression(float *x, float *y)
{
	x[0] = x[0] + x[2];
	y[0] = y[0] + y[2];
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_glob	glob;
	void	*param[4];
	int		i;

	insert_glob(&glob);
	i = 0;
	if (argc != 2)
		return (ft_report("usage: ./fdf [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_report("Cannot open map.\n"));
	map = NULL;
	if ((glob.h = read_map(fd, &map)) == -1)
		return (ft_report("read_map error"));
	scaling(map, &glob);
	color_map(map, &glob);
	glob.h = glob.h * glob.scale;
	insert_param(param);
	param[2] = map;
	param[3] = &glob;
	mlx_loop_hook(param[0], animacion, param);
	mlx_hook(param[1], 2, 0, key_press, param);
	mlx_loop(param[0]);
}
