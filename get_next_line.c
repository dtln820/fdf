/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:09:54 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/16 15:17:09 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_space(char **str, int i, int *strsize)
{
	char	*temp;
	int		j;

	j = 0;
	temp = (char *)malloc(sizeof(char) * (*strsize) * 2);
	while (j < i)
	{
		temp[j] = (*str)[j];
		j++;
	}
	if (*str)
		free(*str);
	*strsize *= 2;
	*str = temp;
}

void	add_char(char c, int i, char **line, int *strsize)
{
	if (i + 1 > (*strsize))
		create_space(line, i, strsize);
	(*line)[i] = c;
}

char	get_char(int fd)
{
	static char buff[BUFF_SIZE];
	int			nr;
	char		c;

	FV;
	SV;
	c = 0;
	if (prevfd != fd)
	{
		index = 0;
		prevfd = fd;
		while (index < BUFF_SIZE)
			buff[index++] = 0;
		index = 0;
	}
	if (index == 0)
		if ((nr = read(fd, buff, BUFF_SIZE)) == -1 || nr == 0)
			return (nr);
	if (index < BUFF_SIZE && buff[index])
		c = buff[index++];
	if (index == BUFF_SIZE || buff[index] == '\0')
		prevfd = -1;
	return (c);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		strsize;
	char	c;

	i = 0;
	strsize = BUFF_SIZE + 1;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((c = get_char(fd)) != '\n' && c != -1 && c != 0)
		add_char(c, i++, line, &strsize);
	(*line)[i] = '\0';
	if (c == '\n' && i == 0)
		return (1);
	if ((*line)[0] != '\0')
		return (1);
	return (c);
}
