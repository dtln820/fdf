#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

void	draw_line(int x0, int y0, int x1, int y1);

void	draw_points(char **str);

void	draw_map(int fd, char *path);

#endif