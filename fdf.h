/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:12:12 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/21 15:19:59 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define FI 2.0943951024

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	double		alfa;
	double		zoom;
	double		scale;
	double		xrot;
	double		yrot;
	int			axe;
	int			sum;
	int			**result;
	int			lines;
	int			cols;
}				t_info;

typedef struct	s_points
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_points;

char			*ft_strncpy(char *dest, const char *src, size_t n);

char			*ft_strnew(size_t size);

char			**ft_strsplit(char const *s, char c);

void			draw_line(t_points *point, t_info *st);

void			draw_points(char **str, int x, t_info *st);

void			draw_map(int fd, char *path, t_info *st);

char			**ft_strsplit(char const *s, char c);

char			*ft_strnew(size_t size);

char			*ft_strncpy(char *dest, const char *src, size_t n);

int				draw_lines(void *ss);

void			draw_body(double dvar[], int ivar[], int **result, t_info *st);

void			draw_horizont(double *dvar, int *ivar, int **res, t_info *st);

void			draw_vertical(double dvar[], int ivar[], int **res, t_info *st);

int				key_hook(int k, void *ss);

void			clear_window(t_info *st);

void			ft_putstr(char const *s);

int				ft_atoi(const char *str);

void			ft_sendbody(t_info *st, double dvar[]);

void			ft_sendhv(t_info *st, double dvar[]);

void			key_hook2(int k, void *ss);

#endif
