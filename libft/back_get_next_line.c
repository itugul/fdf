/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:29:29 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/18 16:11:32 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dict			*create_map(size_t size)
{
	t_dict				*file;
	size_t				i;

	file = (t_dict *)malloc(sizeof(t_dict) * (size + 1));
	if (file == NULL)
		return (file);
	i = 0;
	while (i < size)
	{
		file[i].cont = ft_strnew(1);
		if (file[i].cont == NULL)
			return (file);
		i++;
	}
	file[i].key = 0;
	file[i].cont = NULL;
	return (file);
}

static t_dict			*ext_map(t_dict *file, int i, const int fd, char *str)
{
	t_dict				*new;
	int					j;

	j = 0;
	new = (t_dict *)malloc(sizeof(t_dict) * (i + 2));
	while (j < i)
	{
		if (file[j].cont)
			new[j].cont = ft_strdup(file[j].cont);
		free(file[j].cont);
		new[j].key = file[j].key;
		j++;
	}
	new[i].key = fd;
	new[i].cont = ft_strdup(str);
	new[i + 1].key = 0;
	new[i + 1].cont = NULL;
	free(file);
	file = NULL;
	return (new);
}

static int				read_in_buf(int fd, t_dict *file, int i)
{
	int					j;
	char				*temp;
	char				tmp[BUFF_SIZE + 1];

	j = 1;
	while (!(ft_strchr(file[i].cont, '\n'))
		&& (j = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[j] = '\0';
		temp = file[i].cont;
		if (!(file[i].cont = ft_strjoin(temp, tmp)))
			return (-1);
		ft_strdel(&temp);
	}
	return (j);
}

static int				sending(t_dict *file, char **line, int i)
{
	char				*temp;

	if (file[i].cont[0] == '\0')
		return (0);
	if (ft_strchr(file[i].cont, '\n'))
	{
		temp = file[i].cont;
		*line = ft_strsub(file[i].cont, 0,
			ft_strchr(file[i].cont,'\n') - file[i].cont);
		file[i].cont = ft_strdup(ft_strchr(file[i].cont, '\n') + 1);
		ft_strdel(&temp);
	}
	else
	{
		*line = ft_strdup(file[i].cont);
		ft_strdel(&file[i].cont);
	}
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static t_dict		*file;
	int					i;
	int					ret;

	if (file == NULL)
	{
		file = create_map(1);
		file[0].key = fd;
		if (file == NULL || file[0].cont == NULL)
			return (-1);
	}
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	i = 0;
	while (file[i].key != fd && file[i].cont)
		i++;
	if (!(file[i].cont))
		file = ext_map(file, i, fd, "");
	ret = read_in_buf(fd, file, i);
	if ((ret == 0 || file[i].cont[0] == '\0')
		&& !(file[i].cont))
		return (0);
	if (ret == -1)
		return (-1);
	return (sending(file, line, i));
}
