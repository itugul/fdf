/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:05 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/25 22:56:35 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# define DEF_COLOR 16777215 / 2

typedef struct s_map	t_map;

struct					s_map
{
	int				line_num;
	float			anim_x;
	float			anim_y;
	float			anim_z;
	float			fin_x;
	float			fin_y;
	float			fin_z;
	int				color;
	struct s_map	*next;
	struct s_map	*up;
};

typedef struct s_glob	t_glob;

struct					s_glob
{
	float	scale;
	float	scale_old;
	int		indent_x;
	int		indent_y;
	int		anim_flag;
	int		h;
	int		h_a;
};


void				key_press78(void **param);
int					key_press(int keycode, void **param);
void					key_press2(int keycode, void **param);
void				key_press78(void **param);
void				key_press69(void **param);
void				key_press126(void **param);
void				key_press125(void **param);
void				key_press123(void **param);
void				key_press124(void **param);
void				key_press88(void **param);

void				key_press83(void **param);
void				key_press84(void **param);
void				key_press86(void **param);
void				key_press89(void **param);
void				key_press91(void **param);
void				key_press53(void **param);

t_map				*getNth(t_map *head, int n);
float				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(t_map start, t_glob *glob, t_map end);
void			color_map(t_map *map, t_glob *glob);
void				draw_dda(void **param, t_map *map, t_map *end);
int					hex_to_int(const char *s);
void				push(t_map **head, int *data);
int					read_map(int fd, t_map **map);
void			x_rot(t_map *map, int sig);
void			y_rot(t_map *map, int sig);
void			z_rot(t_map *map, int sig);
void			iso(t_map *tmp, t_glob	*glob);
void			draw_map(void **param);
int					animacion(void **param);
void				scaling(t_map *tmp, t_glob *glob);

#endif
