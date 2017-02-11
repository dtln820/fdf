#include "fdf.h"

void	draw_line(int x0, int y0, int x1, int y1, t_info *st)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = dx+dy, e2;

	while(1)
	{
		mlx_pixel_put(st->mlx, st->win, x0, y0, 0xFFFFFF);
		if (x0==x1 && y0==y1) break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
   }
}

int		key_hook(int k, void *ss)
{
	t_info *st;

	st = (t_info*)ss;
	if (k == 2)
		st->sum += 10;
	else
		st->sum -= 10;
	return (draw_lines(st));
}

int		main(int argc, char *argv[])
{
	t_info	*st;
	st = malloc(sizeof(t_info));
	if (argc < 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		return (0);
	}
	int fd = open(argv[1], O_RDONLY);
	st->mlx = mlx_init();
	st->win = mlx_new_window(st->mlx, 1280, 720, "FDF");
	draw_map(fd, argv[1], st);
	st->zoom  = 1;
	st->sum = 270;
	st->alfa = 5.235987756;
	mlx_key_hook(st->win, &key_hook, st);
	mlx_expose_hook(st->win, &draw_lines, st);
	mlx_loop(st->mlx);
	return (0);
}
