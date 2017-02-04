#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	*mlx;
void	*win;

void	draw_line(int x0, int y0, int x1, int y1)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = dx+dy, e2; /* error value e_xy */
	for(;;){  /* loop */
		mlx_pixel_put(mlx, win, x0, y0, 255);
		if (x0==x1 && y0==y1) break;
		e2 = 2*err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
   }
}

void	draw_map(int fd)
{
	char	*str = NULL;

	while (get_next_line(fd, &str) > 0)
	{
	}
}

int		main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 800, 600, "42");
	draw_map(fd);
	//mlx_loop(mlx);
	return (0);
}