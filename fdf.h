/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:05 by fbrekke           #+#    #+#             */
/*   Updated: 2019/05/08 11:38:40 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

# define VECT 128

typedef struct s_map	t_map;

struct					s_map
{
	int				x;
	int				y;
	int				z;
	int				collor;
	struct s_map	*next;
	struct s_map	*up;
};

void				push(t_map **head, int *data);

#endif
