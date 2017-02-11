#ifndef FDF_H
# define FDF_H
# define fi 2.0943951024

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct  s_info
{
  void    *mlx;
  void    *win;
  double  alfa;
  int     zoom;
  int     sum;
  int     **result;
  int     lines;
  int     cols;
}               t_info;

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strnew(size_t size);

char	**ft_strsplit(char const *s, char c);

void	draw_line(int x0, int y0, int x1, int y1, t_info *st);

void	draw_points(char **str, int x, t_info *st);

void	draw_map(int fd, char *path, t_info *st);

char	**ft_strsplit(char const *s, char c);

char	*ft_strnew(size_t size);

char	*ft_strncpy(char *dest, const char *src, size_t n);

int   draw_lines(void *ss);

void	draw_body(double dvar[], int ivar[], int **result, t_info *st);

void	draw_horizont(double *dvar, int *ivar, int **result, int lines, t_info *st);

void	draw_vertical(double dvar[], int ivar[], int **result, int cols, t_info *st);

int   key_hook(int k, void *ss);

#endif
