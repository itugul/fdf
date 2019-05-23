/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:24:14 by fbrekke           #+#    #+#             */
/*   Updated: 2019/05/08 12:04:51 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void				push(t_map **head, int *data)
{
	t_map			*tmp;

	if (!(tmp = (t_map*)malloc(sizeof(t_map))))
		return ;
	tmp->x = data[0];
	tmp->y = data[1];
	tmp->z = data[2];
	tmp->collor = data[3];
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
// 	ft_putchar('X');
// 	return (0);
// }


// line drawing!!!!
void		draw_DDA(void *mlx_ptr, void *win_ptr, float *x, float *y)
{
	int		step;
	int		i;

	step = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
	x[2] = ft_abs(x[1] - x[0]) / step;
	y[2] = ft_abs(y[1] - y[0]) / step;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], 0x0000FF);
		printf("step = %d/%d\nx[0] = %f\ny[0] = %f\n", i, step, x[0], y[0]);
		if (x[0] < x[1])
			x[0] = x[0] + x[2] > x[1] ? x[1] : x[0] + x[2];
		if (y[0] < y[1])
			y[0] = y[0] + y[2] > y[1] ? y[1] : y[0] + y[2];
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
	int		xyzc[4];
	int 	n[2];

	n[0] = 0;
	n[1] = 0;
	xyzc[0] = 0;
	xyzc[1] = 0;
	xyzc[2] = 0;
	xyzc[3] = 0;

	wrd = ft_strnew(1);

	t = 0;
	// printf("BUFF_SIZE = [%d]\n", BUFF_SIZE);
	while ((t = get_next_line(fd, &line)) > 0)
	{
		// printf("1)line = [%s]\n", line);
		tmp = line;
		n[0] = n[1];
		n[1] = ft_num_words(line, ' ');
		if (n[0] != 0 && n[1] != n[0])
			return (ft_report("not valid map"));
		while (*line != '\0' && ((d = ft_pars(&line, " ,", &wrd))!= -1) && (xyzc[1] < n[1]))
		{
			// printf("d = [%c]\n", d);
			// printf("wrd = [%s]\n", wrd);
			// printf("line = [%s]\n", line);

			if (d == ',')
			{
				(*map)->collor = hex_to_int(wrd);
				// printf("1)map[%d][%d] = %d, collor = %d\n", (*map)->x, (*map)->y, (*map)->z, (*map)->collor);
			}
			else
			{
				xyzc[2] = ft_atoi(wrd);
				push(map, xyzc);
				if (xyzc[0] > 0)
					(*map)->up = getNth(*map, n[1]);
				// printf("2)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
				xyzc[1]++;
			}
		}
		xyzc[0]++;
		xyzc[1] = 0;
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
	return (0);
}

static void	iso(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	x[3];
	float	y[3];
	int		fd;
	t_map	*map;
	t_map	*tmp;
	int		i = 0;

	if (argc != 2)
		return (ft_report("usage: ./fdf [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_report("Cannot open map.\n"));
	map = NULL;
	if (read_map(fd, &map) == -1)
		return (ft_report("read_map error"));
	// printf("%d ", map[0][0]);
	// ft_putendl("");
	// print_int_arr(map);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");
	// draw_web(mlx_ptr, win_ptr, 10, 10);

	tmp = map;
	// printf("x = %d\n", tmp->x);
	// printf("y = %d\n", tmp->y);
	// printf("z = %d\n", tmp->z);
	while (tmp->next != NULL)
	{
		// ft_putendl("!!!");
		// printf("x = %d, y = %d, z = %d", tmp->x, tmp->y, tmp->z);
		// iso(&tmp->x, &tmp->y, tmp->z);
		x[0] = tmp->x * 25 + 25;
		y[0] = tmp->y * 25 + 25;
		x[1] = tmp->next->x * 25 + 25;
		y[1] = tmp->next->y * 25 + 25;
		x[2] = 0;
		y[2] = 0;
		draw_DDA(mlx_ptr, win_ptr, y, x);
		if (tmp->up)
		{
			x[1] = tmp->up->x * 25 + 25;
			y[1] = tmp->up->y * 25 + 25;
			draw_DDA(mlx_ptr, win_ptr, y, x);
		}
	}

	//draw_DDA(mlx_ptr, win_ptr, x, y);
	// mlx_string_put (mlx_ptr, win_ptr, 0, 0, 0xFFFFFF, "TEST");
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
