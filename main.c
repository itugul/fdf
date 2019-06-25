/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:04:25 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/26 00:20:47 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				push(t_map **head, int *data)
{
	t_map			*tmp;

	if (!(tmp = (t_map*)malloc(sizeof(t_map))))
		return ;
	tmp->line_num = data[0];
	tmp->anim_x = 0;
	tmp->anim_y = 0;
	tmp->anim_z = 0;
	tmp->fin_x = data[0];
	tmp->fin_y = data[1];
	tmp->fin_z = data[2];
	tmp->color = DEF_COLOR;
	tmp->next = (*head);
	tmp->up = NULL;
	(*head) = tmp;
}

t_map				*getnth(t_map *head, int n)
{
	int				i;

	i = 0;
	while (i < n && head)
	{
		head = head->next;
		i++;
	}
	return (head);
}

float	percent(int start, int end, int current)
{
	float placement;
	float distance;

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

void	color_map(t_map *map, t_glob *glob)
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

void		draw_dda(void **param, t_map *map, t_map *end)
{
	int		step;
	int		i;
	float	x[3];
	float	y[3];
	int		color;

	x[0] = map->anim_y + ((t_glob **)param)[3]->indent_y;
	x[1] = end->anim_y + ((t_glob **)param)[3]->indent_y;
	y[0] = map->anim_x + ((t_glob **)param)[3]->indent_x;
	y[1] = end->anim_x + ((t_glob **)param)[3]->indent_x;
	step = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
	x[2] = (x[1] - x[0]) / step;
	y[2] = (y[1] - y[0]) / step;
	i = 0;
	while (i < step)
	{
		color = get_color(*map, param[3], *end);
		mlx_pixel_put(param[0], param[1], x[0], y[0], color);
		x[0] = x[0] + x[2];
		y[0] = y[0] + y[2];
		i++;
	}
}

int		hex_to_int(const char *s)
{
	int i;
	int	k;
	int	b;
	int j;

	i = 0;
	k = 1;
	j = ft_strlen(s);
	while (j-- > 2)
	{
		if (47 < s[j] && s[j] < 58)
			b = s[j] - 48;
		else if (64 < s[j] && s[j] < 71)
			b = s[j] - 55;
		else if (s[j] == 'x' && s[j - 1] == '0')
			j = 0;
		i += b * k;
		k *= 16;
	}
	return (i);
}

int			*pars_line(t_map **map, char **line, int *xyzh, int *n)
{
	char	d;
	char	*wrd;

	wrd = ft_strnew(1);
	while (*line != '\0' && ((d = ft_pars(line, " ,", &wrd)) != -1)
		&& (xyzh[1] < n[1]))
	{
		if (d == ',')
			(*map)->color = hex_to_int(wrd);
		else
		{
			xyzh[2] = ft_atoi(wrd);
			xyzh[3] = xyzh[3] < ft_abs(xyzh[2]) ? ft_abs(xyzh[2]) : xyzh[3];
			push(map, xyzh);
			if (xyzh[0] > 0)
				(*map)->up = getnth(*map, n[1]);
			xyzh[1]++;
		}
	}
	ft_strdel(&wrd);
	return (xyzh);
}

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

int			read_map(int fd, t_map **map)
{
	char	*line;
	char	*tmp;
	int		*xyzh;
	int		nth[4];

	xyzh = (int *)malloc(sizeof(int) * 4);
	insert_var(xyzh, nth);
	while ((nth[2] = get_next_line(fd, &line)) > 0)
	{
		tmp = line;
		nth[0] = nth[1];
		nth[1] = ft_num_words(line, ' ');
		if (nth[0] != 0 && nth[1] != nth[0])
			return (ft_report("not valid map"));
		pars_line(map, &line, xyzh, nth);
		xyzh[0]++;
		xyzh[1] = 0;
		ft_strdel(&tmp);
	}
	nth[3] = xyzh[3];
	free(xyzh);
	if (nth[2] == -1)
		return (ft_report("read error"));
	return (nth[3]);
}

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

void	iso(t_map *tmp, t_glob *glob)
{
	while (tmp != NULL)
	{
		if (glob->anim_flag == 0)
			tmp->anim_z = glob->scale > glob->scale_old ?
				tmp->anim_z + tmp->anim_z / glob->scale_old :
					tmp->anim_z - tmp->anim_z / glob->scale_old;
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

void	draw_map(void **param)
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
}

int	animacion(void **param)
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
		glob->anim_flag = 0;
	return (0);
}

void	scaling(t_map *tmp, t_glob *glob)
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

void		insert_glob(t_glob *glob)
{
	glob->scale = 5.0;
	glob->scale_old = 5.0;
	glob->indent_x = 500;
	glob->indent_y = 900;
	glob->anim_flag = 0;
	glob->h = 0;
	glob->h_a = 0;
}

void		insert_param(void **param)
{
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 2500, 1300, "test");
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
	mlx_hook(param[1], 5, 0, key_press, param);
	mlx_loop(param[0]);
}
