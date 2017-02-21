/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_help2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:31:28 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/21 14:31:30 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizont(double dv[], int iv[], int **r, t_info *st)
{
	int	lines;

	lines = st->lines;
	iv[0] = lines * 20;
	iv[3] = iv[7] * 20;
	iv[1] = lines * 20;
	iv[4] = (iv[7] + 1) * 20;
	dv[0] = iv[0] * cos(dv[6] + st->xrot) + iv[3] * cos(dv[6] + FI + st->yrot)
	+ st->scale * r[lines - 1][iv[7] - 1] * cos(dv[6] - FI) + iv[8];
	dv[3] = iv[0] * sin(dv[6] + st->xrot) + iv[3] * sin(dv[6] + FI + st->yrot)
	+ st->scale * r[lines - 1][iv[7] - 1] * sin(dv[6] - FI) + iv[8];
	dv[1] = iv[1] * cos(dv[6] + st->xrot) + iv[4] * cos(dv[6] + FI + st->yrot)
	+ st->scale * r[lines - 1][iv[7]] * cos(dv[6] - FI) + iv[8];
	dv[4] = iv[1] * sin(dv[6] + st->xrot) + iv[4] * sin(dv[6] + FI + st->yrot)
	+ st->scale * r[lines - 1][iv[7]] * sin(dv[6] - FI) + iv[8];
	ft_sendhv(st, dv);
}

void	draw_vertical(double dv[], int iv[], int **r, t_info *st)
{
	int	cols;

	cols = st->cols;
	iv[0] = iv[6] * 20;
	iv[3] = cols * 20;
	iv[1] = (iv[6] + 1) * 20;
	iv[4] = cols * 20;
	dv[0] = iv[0] * cos(dv[6] + st->xrot) + iv[3] * cos(dv[6] + FI + st->yrot)
	+ st->scale * r[iv[6] - 1][cols - 1] * cos(dv[6] - FI) + iv[8];
	dv[3] = iv[0] * sin(dv[6] + st->xrot) + iv[3] * sin(dv[6] + FI + st->yrot)
	+ st->scale * r[iv[6] - 1][cols - 1] * sin(dv[6] - FI) + iv[8];
	dv[1] = iv[1] * cos(dv[6] + st->xrot) + iv[4] * cos(dv[6] + FI + st->yrot)
	+ st->scale * r[iv[6]][cols - 1] * cos(dv[6] - FI) + iv[8];
	dv[4] = iv[1] * sin(dv[6] + st->xrot) + iv[4] * sin(dv[6] + FI + st->yrot)
	+ st->scale * r[iv[6]][cols - 1] * sin(dv[6] - FI) + iv[8];
	ft_sendhv(st, dv);
}

void	clear_write(t_info *st)
{
	mlx_clear_window(st->mlx, st->win);
	mlx_string_put(st->mlx, st->win, 10, 60, 0xFFFFFF, "W/S - Up/Down");
	mlx_string_put(st->mlx, st->win, 10, 80, 0xFFFFFF, "A/D - Left/Right");
	mlx_string_put(st->mlx, st->win, 10, 100, 0xFFFFFF, "Z/Q - Zoom");
	mlx_string_put(st->mlx, st->win, 10, 120, 0xFFFFFF, "E/R - Scale");
	mlx_string_put(st->mlx, st->win, 10, 140, 0xFFFFFF, "F/G - Rotate X");
	mlx_string_put(st->mlx, st->win, 10, 160, 0xFFFFFF, "C/V - Rotate Y");
	mlx_string_put(st->mlx, st->win, 10, 40, 0xFFFFFF, "Escape - Quit");
}

int		draw_lines(void *ss)
{
	double	dvar[7];
	int		ivar[11];
	t_info	*st;

	st = (t_info*)ss;
	dvar[6] = st->alfa;
	ivar[10] = 0;
	ivar[6] = 1;
	ivar[8] = st->sum;
	clear_write(st);
	while (ivar[6] <= st->lines - 1)
	{
		ivar[7] = 1;
		while (ivar[7] <= st->cols - 1)
		{
			draw_body(dvar, ivar, st->result, st);
			if (ivar[10] == 0)
				draw_horizont(dvar, ivar, st->result, st);
			ivar[7]++;
		}
		ivar[10] = 1;
		draw_vertical(dvar, ivar, st->result, st);
		ivar[6]++;
	}
	return (0);
}
