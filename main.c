/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:11:41 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/21 15:11:42 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_points *point, t_info *st)
{
	int	vars[6];

	vars[0] = abs(point->x1 - point->x0);
	vars[1] = -abs(point->y1 - point->y0);
	vars[2] = point->x0 < point->x1 ? 1 : -1;
	vars[3] = point->y0 < point->y1 ? 1 : -1;
	vars[4] = vars[0] + vars[1];
	while (1)
	{
		mlx_pixel_put(st->mlx, st->win, point->x0, point->y0, 0xFFFFFF);
		if (point->x0 == point->x1 && point->y0 == point->y1)
			break ;
		vars[5] = 2 * vars[4];
		if (vars[5] >= vars[1])
		{
			vars[4] += vars[1];
			point->x0 += vars[2];
		}
		if (vars[5] <= vars[0])
		{
			vars[4] += vars[0];
			point->y0 += vars[3];
		}
	}
}

int		key_hook(int k, void *ss)
{
	t_info *st;

	st = (t_info*)ss;
	if (k == 13)
		st->sum -= 20;
	else if (k == 1)
		st->sum += 20;
	else if (k == 6)
		st->zoom += 0.1;
	else if (k == 12)
		st->zoom -= 0.1;
	else if (k == 14)
		st->scale += 0.2;
	else if (k == 15)
		st->scale -= 0.2;
	else if (k == 53)
		exit(1);
	else
		key_hook2(k, ss);
	return (draw_lines(st));
}

void	key_hook2(int k, void *ss)
{
	t_info	*st;

	st = (t_info*)ss;
	if (k == 3)
		st->xrot += 0.1;
	else if (k == 5)
		st->xrot -= 0.1;
	else if (k == 8)
		st->yrot += 0.1;
	else if (k == 9)
		st->yrot -= 0.1;
	else if (k == 0)
		st->axe -= 20;
	else if (k == 2)
		st->axe += 20;
	return ;
}

int		main(int argc, char *argv[])
{
	t_info	*st;
	int		fd;

	st = malloc(sizeof(t_info));
	if (argc < 2)
	{
		ft_putstr("Usage: ./fdf");
		ft_putstr(" filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	st->mlx = mlx_init();
	st->win = mlx_new_window(st->mlx, 1280, 720, "FDF");
	draw_map(fd, argv[1], st);
	st->zoom = 1;
	st->sum = 270;
	st->alfa = 5.235987756;
	st->scale = 1;
	st->xrot = 0;
	st->yrot = 0;
	st->axe = 0;
	mlx_key_hook(st->win, &key_hook, st);
	mlx_expose_hook(st->win, &draw_lines, st);
	mlx_loop(st->mlx);
	return (0);
}
