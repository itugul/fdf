/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:24:59 by ehaggon           #+#    #+#             */
/*   Updated: 2019/05/01 04:11:42 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_validator(char **mychrarr, char **line)
{
	size_t			cntr;
	char			*timestack;
	char			*freestack;

	cntr = 0;
	freestack = mychrarr[0];
	while (freestack[cntr] != '\n' && freestack[cntr])
		cntr++;
	if (cntr >= ft_strlen(freestack))
		return (0);
	timestack = &freestack[cntr];
	timestack[0] = '\0';
	*line = ft_strdup(*mychrarr);
	*mychrarr = ft_strdup(timestack + 1);
	free(freestack);
	return (1);
}

static	int			ft_reader(int fd, char *mybuff, char **mycharr, char **line)
{
	char			*timestack;
	int				rslt;

	while ((rslt = read(fd, mybuff, BUFF_SIZE)) > 0)
	{
		mybuff[rslt] = '\0';
		if (mycharr[0])
		{
			timestack = *mycharr;
			*mycharr = ft_strjoin(timestack, mybuff);
			free(timestack);
			timestack = NULL;
		}
		else
			*mycharr = ft_strdup(mybuff);
		if (ft_validator(mycharr, line))
			break ;
	}
	if (rslt > 0)
		return (1);
	else
		return (rslt);
}

int					get_next_line(int const fd, char **line)
{
	static char		*mychar[MAXFILED];
	char			*mybuff;
	int				rslt;

	if (!line || (fd < 0 || fd >= MAXFILED) || (read(fd, mychar[fd], 0) < 0) \
		|| !(mybuff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (mychar[fd])
		if (ft_validator(&mychar[fd], line) != 0)
		{
			free(mybuff);
			return (1);
		}
	ft_bzero(mybuff, BUFF_SIZE);
	rslt = ft_reader(fd, mybuff, &mychar[fd], line);
	free(mybuff);
	if (rslt != 0 || mychar[fd] == NULL || mychar[fd][0] == '\0')
	{
		if (!rslt && line[0])
			line[0] = NULL;
		return (rslt);
	}
	*line = mychar[fd];
	mychar[fd] = NULL;
	return (1);
}
