/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:05 by fbrekke           #+#    #+#             */
/*   Updated: 2019/05/30 17:28:21 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

# define DEF_COLOR 0x0000FF

typedef struct s_map	t_map;

struct					s_map
{
	int				line_num;
	float			x;
	float			y;
	float			z;
	int				color;
	struct s_map	*next;
	struct s_map	*up;
};

void				push(t_map **head, int *data);

#endif
