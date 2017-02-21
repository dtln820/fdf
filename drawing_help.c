/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:28:03 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/21 14:28:05 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(int fd, char *path, t_info *st)
{
	char	**str;
	int		i;

	str = (char**)malloc(sizeof(char*) * 1);
	i = 0;
	while (get_next_line(fd, &(str[0])) > 0)
		i++;
	free(str[0]);
	free(str);
	str = (char**)malloc(sizeof(char*) * (i + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &(str[i])) > 0)
		i++;
	str[i] = 0;
	draw_points(str, i, st);
}

void	draw_points(char **str, int line, t_info *st)
{
	char	**temp;
	int		**result;
	int		i;
	int		j;

	i = 0;
	result = (int**)malloc(sizeof(int*) * line);
	temp = ft_strsplit(str[i], ' ');
	i = 0;
	while (temp[i])
		i++;
	j = -1;
	while (++j < line)
		result[j] = (int*)malloc(sizeof(int) * i);
	i = -1;
	while (str[++i])
	{
		j = -1;
		temp = ft_strsplit(str[i], ' ');
		while (temp[++j])
			result[i][j] = ft_atoi(temp[j]);
	}
	st->result = result;
	st->lines = line;
	st->cols = j;
}

void	ft_sendbody(t_info *st, double dvar[])
{
	t_points	*temp;

	temp = malloc(sizeof(t_points));
	temp->x0 = st->axe + dvar[3] * st->zoom;
	temp->y0 = dvar[0] * st->zoom;
	temp->x1 = st->axe + dvar[4] * st->zoom;
	temp->y1 = dvar[1] * st->zoom;
	draw_line(temp, st);
	temp->x0 = st->axe + dvar[3] * st->zoom;
	temp->y0 = dvar[0] * st->zoom;
	temp->x1 = st->axe + dvar[5] * st->zoom;
	temp->y1 = dvar[2] * st->zoom;
	draw_line(temp, st);
	free(temp);
}

void	draw_body(double dvar[], int ivar[], int **result, t_info *st)
{
	double	tmp[3];

	tmp[0] = dvar[6] + st->xrot;
	tmp[1] = dvar[6] + FI + st->yrot;
	tmp[2] = dvar[6] - FI;
	ivar[0] = ivar[6] * 20;
	ivar[1] = (ivar[6] + 1) * 20;
	ivar[2] = ivar[6] * 20;
	ivar[3] = ivar[7] * 20;
	ivar[4] = ivar[7] * 20;
	ivar[5] = (ivar[7] + 1) * 20;
	dvar[0] = ivar[0] * cos(tmp[0]) + ivar[3] * cos(tmp[1]) +
	st->scale * result[ivar[6] - 1][ivar[7] - 1] * cos(tmp[2]) + ivar[8];
	dvar[3] = ivar[0] * sin(tmp[0]) + ivar[3] * sin(tmp[1]) +
	st->scale * result[ivar[6] - 1][ivar[7] - 1] * sin(tmp[2]) + ivar[8];
	dvar[1] = ivar[1] * cos(tmp[0]) + ivar[4] * cos(tmp[1]) +
	st->scale * result[ivar[6]][ivar[7] - 1] * cos(tmp[2]) + ivar[8];
	dvar[4] = ivar[1] * sin(tmp[0]) + ivar[4] * sin(tmp[1]) +
	st->scale * result[ivar[6]][ivar[7] - 1] * sin(tmp[2]) + ivar[8];
	dvar[2] = ivar[2] * cos(tmp[0]) + ivar[5] * cos(tmp[1]) +
	st->scale * result[ivar[6] - 1][ivar[7]] * cos(tmp[2]) + ivar[8];
	dvar[5] = ivar[2] * sin(tmp[0]) + ivar[5] * sin(tmp[1]) +
	st->scale * result[ivar[6] - 1][ivar[7]] * sin(tmp[2]) + ivar[8];
	ft_sendbody(st, dvar);
}

void	ft_sendhv(t_info *st, double dvar[])
{
	t_points	*temp;

	temp = malloc(sizeof(t_points));
	temp->x0 = st->axe + dvar[3] * st->zoom;
	temp->y0 = dvar[0] * st->zoom;
	temp->x1 = st->axe + dvar[4] * st->zoom;
	temp->y1 = dvar[1] * st->zoom;
	draw_line(temp, st);
	free(temp);
}
