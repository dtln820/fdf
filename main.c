#include "fdf.h"

void	*mlx;
void	*win;

void	draw_line(int x0, int y0, int x1, int y1)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = dx+dy, e2;

	while(1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0xFFFFFF);
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

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		return (0);
	}
	int fd = open(argv[1], O_RDONLY);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "FDF");
	draw_map(fd, argv[1]);
	mlx_loop(mlx);
	return (0);
}
