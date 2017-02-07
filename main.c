#include "fdf.h"

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

void	draw_map(int fd, char *path)
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
	str[i] = 0;
	close(fd);
	fd = open(path, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &(str[i])) > 0)
		i++;
	draw_points(str, i);
}

void	draw_points(char **str, int line)
{
	char	**temp;
	int		**result;
	int		i;
	int		j;

	result = (int**)malloc(sizeof(int*) * line);
	temp = ft_strsplit(str[i], ' ');
	i = 0;
	while (temp[i])
		i++;
	j = -1;
	while (++j < line)
		result[j] = (int*)malloc(sizeof(int) * i);
	i = 0;
	while (str[i])
	{
		j = -1;
		temp = ft_strsplit(str[i], ' ');
		while(temp[++j])
			result[i][j] = atoi(temp[j]);
		i++;
	}
	draw_lines(result, line, j);
}

void	draw_lines(int **result, int lines, int cols)
{
	int		i;
	int		j;
	int		ver;
	int		x[3];
	int		y[3];
	int		sum;
	int		zoom;
	double	u[3];
	double	v[3];
	double	alfa;

	alfa = 5.235987756;

	ver = 0;
	i = 1;
	sum = 270;
	zoom = 1;
	while (i <= lines - 1)
	{
		j = 1;
		while (j <= cols - 1)
		{
			x[0] = i * 20;
			x[1] = (i + 1) * 20;
			x[2] = i * 20;
			y[0] = j * 20;
			y[1] = j * 20;
			y[2] = (j + 1) * 20;
			u[0] = x[0] * cos(alfa) + y[0] * cos(alfa + 2.0943951024) + result[i-1][j-1] * cos(alfa - 2.0943951024) + sum;
			v[0] = x[0] * sin(alfa) + y[0] * sin(alfa + 2.0943951024) + result[i-1][j-1] * sin(alfa - 2.0943951024) + sum;
			u[1] = x[1] * cos(alfa) + y[1] * cos(alfa + 2.0943951024) + result[i][j-1] * cos(alfa - 2.0943951024) + sum;
			v[1] = x[1] * sin(alfa) + y[1] * sin(alfa + 2.0943951024) + result[i][j-1] * sin(alfa - 2.0943951024) + sum;
			u[2] = x[2] * cos(alfa) + y[2] * cos(alfa + 2.0943951024) + result[i-1][j] * cos(alfa - 2.0943951024) + sum;
			v[2] = x[2] * sin(alfa) + y[2] * sin(alfa + 2.0943951024) + result[i-1][j] * sin(alfa - 2.0943951024) + sum;
			draw_line(v[0],u[0], v[1],u[1]);
			draw_line(v[0],u[0], v[2], u[2]);
			if (ver == 0)
			{
				x[0] = lines * 20;
				y[0] = j * 20;
				x[1] = lines * 20;
				y[1] = (j + 1) * 20;
				u[0] = x[0] * cos(alfa) + y[0] * cos(alfa + 2.0943951024) + result[lines-1][j-1] * cos(alfa - 2.0943951024) + sum;
				v[0] = x[0] * sin(alfa) + y[0] * sin(alfa + 2.0943951024) + result[lines-1][j-1] * sin(alfa - 2.0943951024) + sum;
				u[1] = x[1] * cos(alfa) + y[1] * cos(alfa + 2.0943951024) + result[lines-1][j] * cos(alfa - 2.0943951024) + sum;
				v[1] = x[1] * sin(alfa) + y[1] * sin(alfa + 2.0943951024) + result[lines-1][j] * sin(alfa - 2.0943951024) + sum;
				draw_line(v[0],u[0],v[1],u[1]);
			}
			j++;
		}
		ver = 1;
		x[0] = i * 20;
		y[0] = cols * 20;
		x[1] = (i + 1) * 20;
		y[1] = cols * 20;
		u[0] = x[0] * cos(alfa) + y[0] * cos(alfa + 2.0943951024) + result[i-1][cols-1] * cos(alfa - 2.0943951024) + sum;
		v[0] = x[0] * sin(alfa) + y[0] * sin(alfa + 2.0943951024) + result[i-1][cols-1] * sin(alfa - 2.0943951024) + sum;
		u[1] = x[1] * cos(alfa) + y[1] * cos(alfa + 2.0943951024) + result[i][cols - 1] * cos(alfa - 2.0943951024) + sum;
		v[1] = x[1] * sin(alfa) + y[1] * sin(alfa + 2.0943951024) + result[i][cols - 1] * sin(alfa - 2.0943951024) + sum;
		draw_line(v[0],u[0],v[1],u[1]);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "42");
	draw_map(fd, argv[1]);
	mlx_loop(mlx);
	return (0);
}
