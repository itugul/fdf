/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:05 by fbrekke           #+#    #+#             */
/*   Updated: 2019/06/06 18:36:11 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

# define DEF_COLOR 16777215 / 2

typedef struct s_map	t_map;

struct					s_map
{
	int				line_num;
	// float			x;
	// float			y;
	// float			z;
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

void				push(t_map **head, int *data);

#endif
