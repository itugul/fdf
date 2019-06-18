/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:24:14 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/18 16:40:39 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

float				scale = 5;
float				scale_old = 5;
int					indent_x = 500;
int					indent_y = 900;
int					anim_flag = 0;
int					H = 0;
int					h_a = 0;

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

t_map				*get_nth(t_map *head, int n)
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

double	percent(int start, int end, int current)
{
	double			placement;
	double			distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static void	gradient(t_map *map)
{
	double			percentage;
	int				red;
	int				green;
	int				blue;

	while (map->next != NULL)
	{
		percentage = percent(-(H / scale), H / scale, map->anim_z);
		map->color = 16777215 * percentage;
		map = map->next;
	}
}

void		draw_dda(void *mlx_ptr, void *win_ptr, t_map *start, t_map *end)
{
	int				step;
	int				i;
	float			x[3];
	float			y[3];
	int				color;

	x[0] = start->anim_y + indent_y;
	x[1] = end->anim_y + indent_y;
	y[0] = start->anim_x + indent_x;
	y[1] = end->anim_x + indent_x;
	step = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
	x[2] = (x[1] - x[0]) / step;
	y[2] = (y[1] - y[0]) / step;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], end->color);
		x[0] = x[0] + x[2];
		y[0] = y[0] + y[2];
		i++;
	}
}

int		hex_to_int(const char *s)
{
	int				i;
	int				k;
	int				b;
	int				j;

	i = 0;
	k = 1;
	j = ft_strlen(s);
	while (j-- > 2)
	{
		if (s[j] == '0')
			b = 0;
		if (s[j] == '1')
			b = 1;
		if (s[j] == '2')
			b = 2;
		if (s[j] == '3')
			b = 3;
		if (s[j] == '4')
			b = 4;
		if (s[j] == '5')
			b = 5;
		if (s[j] == '6')
			b = 6;
		if (s[j] == '7')
			b = 7;
		if (s[j] == '8')
			b = 8;
		if (s[j] == '9')
			b = 9;
		if (s[j] == 'A')
			b = 10;
		if (s[j] == 'B')
			b = 11;
		if (s[j] == 'C')
			b = 12;
		if (s[j] == 'D')
			b = 13;
		if (s[j] == 'E')
			b = 14;
		if (s[j] == 'F')
			b = 15;
		if (s[j] == 'x' && s[j - 1] == '0')
			j = 0;
		i += b * k;
		k *= 16;
	}
	return (i);
}

int			read_map(int fd, t_map **map)
{
	char			*line;
	char			*tmp;
	char			*wrd;
	char			d;
	int				t;
	int				xyz[3];
	int				n[2];
	int				h;

	n[0] = 0;
	n[1] = 0;
	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
	wrd = ft_strnew(1);
	t = 0;
	h = 0;
	while ((t = get_next_line(fd, &line)) > 0)
	{
		tmp = line;
		n[0] = n[1];
		n[1] = ft_num_words(line, ' ');
		if (n[0] != 0 && n[1] != n[0])
			return (ft_report("not valid map"));
		while (*line != '\0' && ((d = ft_pars(&line, " ,", &wrd)) != -1) && (xyz[1] < n[1]))
		{
			if (d == ',')
				(*map)->color = hex_to_int(wrd);
			else
			{
				xyz[2] = ft_atoi(wrd);
				h = h < ft_abs(xyz[2]) ? ft_abs(xyz[2]) : h;
				push(map, xyz);
				if (xyz[0] > 0)
					(*map)->up = get_nth(*map, n[1]);
				xyz[1]++;
			}
		}
		xyz[0]++;
		xyz[1] = 0;
		ft_strdel(&tmp);
	}
	ft_strdel(&wrd);
	if (t == -1)
		return (ft_report("read error"));
	return (h);
}

static void	x_rot(t_map *map, int sig)
{
	float			y;
	float			z;

	while (map != NULL)
	{
		y = map->anim_y;
		z = map->anim_z;
		map->anim_y = (y * cos(0.1 * sig)) + (z * sin(0.1 * sig));
		map->anim_z = (-y * sin(0.1 * sig)) + (z * cos(0.1 * sig));
		map = map->next;
	}
}

static void	y_rot(t_map *map, int sig)
{
	float			x;
	float			z;

	while (map != NULL)
	{
		x = map->anim_x;
		z = map->anim_z;
		map->anim_x = (x * cos(0.1 * sig)) + (z * sin(0.1 * sig));
		map->anim_z = (-x * sin(0.1 * sig)) + (z * cos(0.1 * sig));
		map = map->next;
	}
}

static void	z_rot(t_map *map, int sig)
{
	float			y;
	float			x;

	while (map != NULL)
	{
		y = map->anim_y;
		x = map->anim_x;
		map->anim_x = (x * cos(0.1 * sig)) - (y * sin(0.1 * sig));
		map->anim_y = (x * sin(0.1 * sig)) + (y * cos(0.1 * sig));
		map = map->next;
	}
}

static void	iso(t_map *tmp)
{
	while (tmp != NULL)
	{
		tmp->anim_x = ((tmp->fin_x * scale) - (tmp->fin_y * scale)) * cos(0.523599);
		tmp->anim_y = -tmp->anim_z + ((tmp->fin_x * scale) + (tmp->fin_y * scale)) * sin(0.523599);
		if (anim_flag == 0)
			tmp->anim_z = scale > scale_old ? tmp->anim_z + tmp->anim_z / (scale - 1) : tmp->anim_z - tmp->anim_z / (scale - 1);
		else
		{
			tmp->anim_z != (tmp->fin_z * scale) && tmp->fin_z > 0 ? tmp->anim_z++ : 0;
			tmp->anim_z != (tmp->fin_z * scale) && tmp->fin_z < 0 ? tmp->anim_z-- : 0;
		}
		tmp = tmp->next;
	}
}

static void	draw_map(void *mlx_ptr, void *win_ptr, t_map *map)
{
	while (map->next != NULL)
	{
		if (map->line_num == map->next->line_num)
		{
			draw_dda(mlx_ptr, win_ptr, map, map->next);
			if (map->up)
			{
				draw_dda(mlx_ptr, win_ptr, map, map->up);
			}
		}
		else
			draw_dda(mlx_ptr, win_ptr, map, map->up);
		map = map->next;
	}
}

int	animacion(void **param)
{
	if (h_a <= H || h_a <= 10)
	{
		anim_flag = 1;
		iso(param[2]);
		z_rot(param[2], -10);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
		h_a++;
	}
	else
		anim_flag = 0;
	return (0);
}

int	key_press(int keycode, void **param)
{
	if (keycode == 78 && scale > 5 && anim_flag == 0)
	{
		scale_old = scale;
		scale--;
		iso(param[2]);
		z_rot(param[2], -10);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 69 && anim_flag == 0)
	{
		scale_old = scale;
		scale++;
		iso(param[2]);
		z_rot(param[2], -10);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 87 && anim_flag == 0)
	{
		z_rot(param[2], -10);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 126 && anim_flag == 0)
	{
		indent_x += 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 125 && anim_flag == 0)
	{
		indent_x -= 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 123 && anim_flag == 0)
	{
		indent_y += 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 124 && anim_flag == 0)
	{
		indent_y -= 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 88 && anim_flag == 0)
	{
		x_rot(param[2], 1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 86 && anim_flag == 0)
	{
		x_rot(param[2], -1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 91 && anim_flag == 0)
	{
		y_rot(param[2], 1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 84 && anim_flag == 0)
	{
		y_rot(param[2], -1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 89 && anim_flag == 0)
	{
		z_rot(param[2], 1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 83 && anim_flag == 0)
	{
		z_rot(param[2], -1);
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	scaling(t_map *tmp)
{
	int				h[2];
	int				w[2];
	int				s;
	float			xy[2];

	h[0] = 0;
	h[1] = 0;
	w[0] = 0;
	w[1] = 0;
	while (tmp != NULL)
	{
		xy[0] = ((tmp->fin_x * scale) - (tmp->fin_y * scale)) * cos(0.523599);
		xy[1] = -(tmp->fin_z * scale) + ((tmp->fin_x * scale) + (tmp->fin_y * scale)) * sin(0.523599);
		h[0] = h[0] > xy[0] ? xy[0] : h[0];
		h[1] = h[1] < xy[0] ? xy[0] : h[1];
		w[0] = w[0] < xy[1] ? xy[1] : w[0];
		w[1] = w[1] < xy[1] ? xy[1] : w[1];
		tmp = tmp->next;
	}
	s = h[1] - h[0] > w[1] - w[0] ? h[1] - h[0] : w[1] - w[0];
	printf("s == %d\n", s);
	scale = 1300 / s >= 1 ? scale * (1300 / s) : scale;
}

int		main(int argc, char **argv)
{
	int				fd;
	t_map			*map;
	void			*param[3];
	int				i;

	i = 0;
	if (argc != 2)
		return (ft_report("usage: ./fdf [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_report("Cannot open map.\n"));
	map = NULL;
	if ((H = read_map(fd, &map)) == -1)
		return (ft_report("read_map error"));
	scaling(map);
	H = H * scale;
	gradient(map);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 2500, 1300, "test");
	param[2] = map;
	mlx_loop_hook(param[0], animacion, param);
	mlx_hook(param[1], 2, 0, key_press, param);
	mlx_loop(param[0]);
}
