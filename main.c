/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:24:14 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/03 14:01:02 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

int SCALE = 15;
int INDENT_X = 300;
int INDENT_Y = 300;
int	ANIM_FLAG = 0;
int	H = 0;

void				push(t_map **head, int *data)
{
	t_map			*tmp;

	if (!(tmp = (t_map*)malloc(sizeof(t_map))))
		return ;
	tmp->line_num = data[0];
	tmp->x = data[0];
	tmp->y = data[1];
	tmp->z = data[2];
	tmp->anim_x = 0;
	tmp->anim_y = 0;
	tmp->anim_z = 0;
	tmp->fin_x = data[0] * SCALE;
	tmp->fin_y = data[1] * SCALE;
	tmp->fin_z = data[2] * SCALE;
	tmp->color = DEF_COLOR;
	tmp->next = (*head);
	tmp->up = NULL;
	(*head) = tmp;
}

t_map				*getNth(t_map *head, int n)
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

// int			deal_key(int key, void *param)
// {
// 	if (key == 78)
// 	{
// 		ft_putchar('-');
// 		SCALE--;
// 		printf("%d\n", SCALE);
// 		// draw_map(param[0], param[1], param[2]);
// 	}
// 	else if (key == 69)
// 	{
// 		ft_putchar('+');
// 		SCALE++;
// 		printf("%d\n", SCALE);
// 	}
// 	return (0);
// }

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

static int	gradient(int i, int step, t_map *start, t_map *end)
{
	double percentage;
	int red;
    int green;
    int blue;

	if (start->color == end->color)
        return (start->color);

	percentage = i / step;

    red = get_light((start->color >> 16) & 0xFF, (end->color >> 16) & 0xFF, percentage);
    green = get_light((start->color >> 8) & 0xFF, (end->color >> 8) & 0xFF, percentage);
    blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void		draw_DDA(void *mlx_ptr, void *win_ptr, t_map *start, t_map *end)
{
	int		step;
	int		i;
	float	x[3];
	float	y[3];
	int		color;

	if (ANIM_FLAG == 1)
	{
		x[0] = (start->y * SCALE) + INDENT_Y;
		x[1] = (end->y * SCALE) + INDENT_Y;
		y[0] = (start->x * SCALE) + INDENT_X + 500;
		y[1] = (end->x * SCALE) + INDENT_X + 500;
	}
	else
	{
		x[0] = start->anim_y + INDENT_Y;
		x[1] = end->anim_y + INDENT_Y;
		y[0] = start->anim_x + INDENT_X + 500;
		y[1] = end->anim_x + INDENT_X + 500;
	}

	step = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
	// x[2] = ft_abs(x[1] - x[0]) / step;
	// y[2] = ft_abs(y[1] - y[0]) / step;
	x[2] = (x[1] - x[0]) / step;
	y[2] = (y[1] - y[0]) / step;
	i = 1;
	// printf("stage = %d/%d\nx[0] = %f\ny[0] = %f\nx[1] = %f\ny[1] = %f\nx[2] = %f\ny[2] = %f\n", i, step, x[0], y[0], x[1], y[1], x[2], y[2]);
	while (i <= step)
	{
		color = gradient(i, step, start, end);
		mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], color);
		// if (x[0] < x[1])
		// 	x[0] = x[0] + x[2] > x[1] ? x[1] : x[0] + x[2];
		// if (y[0] < y[1])
		// 	y[0] = y[0] + y[2] > y[1] ? y[1] : y[0] + y[2];
		x[0] = x[0] + x[2];
		y[0] = y[0] + y[2];
		i++;
	}
}

// rewrite this insanity
int		hex_to_int(const char *s)
{
	int i;
	int	k=1;
	int	b;
	int j;

	i = 0;
	k = 1;
	j = ft_strlen(s);
	while(j-- > 2)
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
	return i;
}

int			read_map(int fd, t_map **map)
{
	char	*line;
	char	*tmp;
	char	*wrd;
	char	d;
	int		t;
	int		xyz[3];
	int 	n[2];
	int 	h;

	n[0] = 0;
	n[1] = 0;
	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;

	wrd = ft_strnew(1);

	t = 0;
	h = 0;
	// printf("BUFF_SIZE = [%d]\n", BUFF_SIZE);
	while ((t = get_next_line(fd, &line)) > 0)
	{
		// printf("1)line = [%s]\n", line);
		tmp = line;
		n[0] = n[1];
		n[1] = ft_num_words(line, ' ');
		// printf("num words = %d\n", n[1]);
		if (n[0] != 0 && n[1] != n[0])
			return (ft_report("not valid map"));
		while (*line != '\0' && ((d = ft_pars(&line, " ,", &wrd))!= -1) && (xyz[1] < n[1]))
		{
			// printf("d = [%c]\n", d);
			// printf("wrd = [%s]\n", wrd);
			// printf("line = [%s]\n", line);

			if (d == ',')
			{
				(*map)->color = hex_to_int(wrd);
				// printf("1)map[%d][%d] = %d, color = %d\n", (*map)->x, (*map)->y, (*map)->z, (*map)->color);
			}
			else
			{
				xyz[2] = ft_atoi(wrd);
				h = h < ft_abs(xyz[2]) ? ft_abs(xyz[2]) : h;
				push(map, xyz);
				if (xyz[0] > 0)
				{
					(*map)->up = getNth(*map, n[1]);
					// if ((*map)->up)
					// 	printf("(*map)->up->x == %d | (*map)->up->y == %d\n", (*map)->up->x, (*map)->up->y);
				}
				// printf("2)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
				xyz[1]++;
			}
		}
		xyz[0]++;
		xyz[1] = 0;
		// ft_putendl("-----------------------------");
		// printf("t = [%d]\n", t);
		// line -= --t;
		// printf("2)line = [%s]\n", line);
		ft_strdel(&tmp);
	}
	// printf("matrix[%d][%d]\n", (*map)->x, (*map)->y);
	ft_strdel(&wrd);
	if (t == -1)
		return (ft_report("read error"));
	return (h);
}

static void	iso(t_map *tmp)
{
	if (ANIM_FLAG == 1)
		tmp->anim_z = tmp->fin_z;
	while (tmp != NULL)
	{
		tmp->anim_x = (tmp->fin_x - tmp->fin_y) * cos(0.523599);
		tmp->anim_y = -tmp->anim_z + (tmp->fin_x + tmp->fin_y) * sin(0.523599);
		tmp->anim_z = tmp->anim_z != tmp->z && tmp->z > 0 ? tmp->anim_z + 1 : tmp->anim_z;
		tmp->anim_z = tmp->anim_z != tmp->z && tmp->z < 0 ? tmp->anim_z - 1 : tmp->anim_z;
		// printf("z = %f\nanim_z = %f\n", tmp->z, tmp->anim_z);
		tmp = tmp->next;
	}
}

static void	draw_map(void *mlx_ptr,void *win_ptr, t_map *map)
{
	while (map->next != NULL)
	{
		if (map->line_num == map->next->line_num)
		{
			// printf("A%d)x[0] = %f | y[0] = %f\n     x[1] = %f | y[1] = %f\n", i, x[0], y[0], x[1], y[1]);
			draw_DDA(mlx_ptr, win_ptr, map, map->next);
			if (map->up)
			{
				// ft_putendl("---------------");
				// printf("B%d)x[0] = %f | y[0] = %f\n*****x[1] = %f | y[1] = %f\n", i, x[0], y[0], x[1], y[1]);
				draw_DDA(mlx_ptr, win_ptr, map, map->up);
				// ft_putendl("---------------");
			}
		}
		else
			draw_DDA(mlx_ptr, win_ptr, map, map->up);

		map = map->next;
	}
	// draw_DDA(mlx_ptr, win_ptr, map, map);
}

int key_press(int keycode, void **param)
{
	if (keycode == 78)
	{
		SCALE--;
		mlx_clear_window(param[0], param[1]);
		iso(param[2]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 69)
	{
		SCALE++;
		mlx_clear_window(param[0], param[1]);
		iso(param[2]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 87)
	{
		SCALE = 15;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 126)
	{
		INDENT_X -= 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 125)
	{
		INDENT_X += 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 123)
	{
		INDENT_Y -= 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 124)
	{
		INDENT_Y += 10;
		mlx_clear_window(param[0], param[1]);
		draw_map(param[0], param[1], param[2]);
	}
	else if (keycode == 76)
	{
		H = H * SCALE;
		while (H >= 0)
		{
			printf("h = %d\n", H);
			// mlx_clear_window(param[0], param[1]);
			sleep(1);
			iso(param[2]);
			draw_map(param[0], param[1], param[2]);
			H--;
		}
		ANIM_FLAG = 1;
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	t_map	*map;
	void	*param[4];


	if (argc != 2)
		return (ft_report("usage: ./fdf [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_report("Cannot open map.\n"));
	map = NULL;
	if ((H = read_map(fd, &map)) == -1)
		return (ft_report("read_map error"));

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1300, 1300, "test");
	param[0] = mlx_ptr;
	param[1] = win_ptr;
	param[2] = map;

	mlx_hook(win_ptr, 2, 0, key_press, param);


	// mlx_string_put (mlx_ptr, win_ptr, 0, 0, 0xFFFFFF, "TEST");

	mlx_loop(mlx_ptr);
}
