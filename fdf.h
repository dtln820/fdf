#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strnew(size_t size);

char	**ft_strsplit(char const *s, char c);

void	draw_line(int x0, int y0, int x1, int y1);

void	draw_points(char **str, int x);

void	draw_map(int fd, char *path);

char	**ft_strsplit(char const *s, char c);

char	*ft_strnew(size_t size);

char	*ft_strncpy(char *dest, const char *src, size_t n);

void	draw_lines(int **result, int lines, int cols);

#endif
