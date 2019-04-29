/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:24:14 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/25 19:44:36 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx.h"
#include "fdf.h"

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
	(*head) = tmp;
}

// int			deal_key(int key, void *param)
// {
// 	ft_putchar('X');
// 	return (0);
// }

// int			draw_web(void *mlx_ptr, void *win_ptr, int h, int w)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	x = 100;
// 	y = 100;
// 	while (y < 60 * w + 101)
// 	{
// 		while (i++ < 60 * w)
// 			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y, 0x0000FF);
// 		y += 60;
// 		i = 0;
// 	}
// 	y = 100;
// 	while (x < 60 * h + 101)
// 	{
// 		while (i++ < 60 * h)
// 			mlx_pixel_put(mlx_ptr, win_ptr, x, y + i, 0x0000FF);
// 		x += 60;
// 		i = 0;
// 	}
// 	return (0);
// }


// line drawing!!!!
// void		draw_DDA(void *mlx_ptr, void *win_ptr, float *x, float *y)
// {
// 	float	l;

// 	l = (ft_abs(x[1] - x[0])) >= (ft_abs(y[1] - y[0])) ?
// 		(ft_abs(x[1] - x[0])) : (ft_abs(y[1] - y[0]));
// 	x[2] = ft_abs(x[1] - x[0]) / l;
// 	y[2] = ft_abs(y[1] - y[0]) / l;
// 	mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], 0x0000FF);
// 	while (x[0] != x[1] && y[0] != y[1])
// 	{
// 		if (x[0] < x[1])
// 			x[0] = x[0] + x[2] > x[1] ? x[1] : x[0] + x[2];
// 		if (y[0] < y[1])
// 			y[0] = y[0] + y[2] > y[1] ? y[1] : y[0] + y[2];
// 		printf("l = %f\nx[0] = %f\ny[0] = %f\n", l, x[0], y[0]);
// 		mlx_pixel_put(mlx_ptr, win_ptr, x[0], y[0], 0x0000FF);
// 	}
// }


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
	while(j-- > 0)
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
		i += b * k;
		k *= 16;
	}
	return i;
}

void	fill_map(t_map **map, int xyzc[4], char *str)
{
	int	t;

	if (ft_strchr(str, '\n'))
	{
		if ((t = ft_strchr(str, '\n') - str) > 0)
		{
			xyzc[2] = ft_atoi(ft_strsub(str, 0, t));
			push(map, xyzc);
			printf("2)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
		}
		xyzc[0]++;
		xyzc[1] = 0;
		ft_putendl("!");
		if (ft_strlen(str) > t + 1)
		{
			xyzc[2] = ft_atoi(ft_strsub(str, t + 1, ft_strlen(str) - t));
			push(map, xyzc);
			printf("3)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
			xyzc[1]++;
		}
	}
	else
	{
		xyzc[2] = ft_atoi(str);
		push(map, xyzc);
		printf("4)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
		xyzc[1]++;
	}
}

// Old version
// int			read_map(int fd, t_map **map)
// {
// 	char	*line;
// 	char	*wrd;
// 	char	*d;
// 	int		t;
// 	int		xyzc[4];

// 	xyzc[0] = 0;
// 	xyzc[1] = 0;
// 	xyzc[2] = 0;
// 	xyzc[3] = 0;

// 	d = ft_strnew(1);
// 	wrd = ft_strnew(1);
// 	line = ft_strnew(BUFF_SIZE + 1);
// 	while ((t = read(fd, line, BUFF_SIZE)) > 0)
// 	{
// 		line[t] = '\0';
// 		ft_putendl(line);
// 		// wrd = ft_strtok(line, " ");
// 		d = ft_pars(&line, " ", &wrd);
// 		printf("wrd = %s\n", wrd);
// 		fill_map(map, xyzc, wrd);
// 		// while (wrd != NULL && (wrd = ft_strtok(NULL, " ")) != NULL)
// 		while (wrd != NULL && (d = ft_pars(&line, " ", &wrd)) != NULL)
// 			fill_map(map, xyzc, wrd);
// 	}
// 	if (t == -1)
// 		return (ft_report("read error"));
// 	printf("matrix[%d][%d]\n", (*map)->x, (*map)->y);
// 	ft_strdel(&line);
// 	ft_strdel(&wrd);
// 	return (0);
// }

int			read_map(int fd, t_map **map)
{
	char	*line;
	char	*tmp;
	char	*wrd;
	char	*d;
	int		t;
	int		xyzc[4];

	xyzc[0] = 0;
	xyzc[1] = 0;
	xyzc[2] = 0;
	xyzc[3] = 0;

	d = ft_strnew(1);
	wrd = ft_strnew(1);

	t = 0;
	printf("BUFF_SIZE = [%d]\n", BUFF_SIZE);
	while ((t = get_next_line(fd, &line)) && t > 0)
	{
		printf("1)line = [%s]\n", line);
		tmp = line;
		while (*line != '\0' &&(d = ft_pars(&line, " ,", &wrd)) && *d != '\0')
		{
			if (*d == ',')
			{
				(*map)->collor = hex_to_int(wrd);
				printf("1)map[%d][%d] = %d, collor = %d\n", (*map)->x, (*map)->y, (*map)->z, (*map)->collor);
			}
			else
			{
				xyzc[2] = ft_atoi(wrd);
				push(map, xyzc);
				printf("2)map[%d][%d] = %d\n", (*map)->x, (*map)->y, (*map)->z);
				xyzc[1]++;
			}
		}
		xyzc[0]++;
		xyzc[1] = 0;
		ft_putendl("-----------------------------");
		printf("t = [%d]\n", t);
		// line -= --t;
		// printf("2)line = [%s]\n", line);
		ft_strdel(&tmp);
	}
	printf("matrix[%d][%d]\n", (*map)->x, (*map)->y);
	ft_strdel(&wrd);
	ft_strdel(&d);
	if (t == -1)
		return (ft_report("read error"));
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	// float	x[3] = {100, 343, 0};
	// float	y[3] = {100, 600, 0};
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (ft_report("usage: ./fdf [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_report("Cannot open map.\n"));
	if (read_map(fd, &map) == -1)
		return (ft_report("read_map error"));
	fd = ft_report("end");
	// printf("%d ", map[0][0]);
	// ft_putendl("");
	// print_int_arr(map);

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 800, 800, "test");
	// draw_web(mlx_ptr, win_ptr, 10, 10);
	// draw_DDA(mlx_ptr, win_ptr, x, y);
	// mlx_string_put (mlx_ptr, win_ptr, 0, 0, 0xFFFFFF, "TEST");
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	// mlx_loop(mlx_ptr);
}
