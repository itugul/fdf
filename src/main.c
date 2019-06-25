/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:04:25 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 00:36:02 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_hook(param[1], 5, 0, key_press, param);
	mlx_loop(param[0]);
}
