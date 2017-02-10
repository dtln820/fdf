#include "fdf.h"

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

void draw_body(double dvar[], int ivar[], int **result)
{
	ivar[0] = ivar[6] * 20;
	ivar[1] = (ivar[6] + 1) * 20;
	ivar[2] = ivar[6] * 20;
	ivar[3] = ivar[7] * 20;
	ivar[4] = ivar[7] * 20;
	ivar[5] = (ivar[7] + 1) * 20;
	dvar[0] = ivar[0] * cos(dvar[6]) + ivar[3] * cos(dvar[6] + 2.0943951024) + result[ivar[6] - 1][ivar[7] - 1] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[3] = ivar[0] * sin(dvar[6]) + ivar[3] * sin(dvar[6] + 2.0943951024) + result[ivar[6] - 1][ivar[7] - 1] * sin(dvar[6] - 2.0943951024) + ivar[8];
	dvar[1] = ivar[1] * cos(dvar[6]) + ivar[4] * cos(dvar[6] + 2.0943951024) + result[ivar[6]][ivar[7] - 1] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[4] = ivar[1] * sin(dvar[6]) + ivar[4] * sin(dvar[6] + 2.0943951024) + result[ivar[6]][ivar[7] - 1] * sin(dvar[6] - 2.0943951024) + ivar[8];
	dvar[2] = ivar[2] * cos(dvar[6]) + ivar[5] * cos(dvar[6] + 2.0943951024) + result[ivar[6] - 1][ivar[7]] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[5] = ivar[2] * sin(dvar[6]) + ivar[5] * sin(dvar[6] + 2.0943951024) + result[ivar[6] - 1][ivar[7]] * sin(dvar[6] - 2.0943951024) + ivar[8];
	draw_line(dvar[3],dvar[0], dvar[4],dvar[1]);
	draw_line(dvar[3],dvar[0], dvar[5], dvar[2]);
}

void	draw_horizont(double dvar[], int ivar[], int **result, int lines)
{
	ivar[0] = lines * 20;
	ivar[3] = ivar[7] * 20;
	ivar[1] = lines * 20;
	ivar[4] = (ivar[7] + 1) * 20;
	dvar[0] = ivar[0] * cos(dvar[6]) + ivar[3] * cos(dvar[6] + 2.0943951024) + result[lines-1][ivar[7] - 1] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[3] = ivar[0] * sin(dvar[6]) + ivar[3] * sin(dvar[6] + 2.0943951024) + result[lines-1][ivar[7] - 1] * sin(dvar[6] - 2.0943951024) + ivar[8];
	dvar[1] = ivar[1] * cos(dvar[6]) + ivar[4] * cos(dvar[6] + 2.0943951024) + result[lines-1][ivar[7]] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[4] = ivar[1] * sin(dvar[6]) + ivar[4] * sin(dvar[6] + 2.0943951024) + result[lines-1][ivar[7]] * sin(dvar[6] - 2.0943951024) + ivar[8];
	draw_line(dvar[3],dvar[0],dvar[4],dvar[1]);
}

void	draw_vertical(double dvar[], int ivar[], int **result, int cols)
{
	ivar[0] = ivar[6] * 20;
	ivar[3] = cols * 20;
	ivar[1] = (ivar[6] + 1) * 20;
	ivar[4] = cols * 20;
	dvar[0] = ivar[0] * cos(dvar[6]) + ivar[3] * cos(dvar[6] + 2.0943951024) + result[ivar[6] - 1][cols - 1] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[3] = ivar[0] * sin(dvar[6]) + ivar[3] * sin(dvar[6] + 2.0943951024) + result[ivar[6] - 1][cols - 1] * sin(dvar[6] - 2.0943951024) + ivar[8];
	dvar[1] = ivar[1] * cos(dvar[6]) + ivar[4] * cos(dvar[6] + 2.0943951024) + result[ivar[6]][cols - 1] * cos(dvar[6] - 2.0943951024) + ivar[8];
	dvar[4] = ivar[1] * sin(dvar[6]) + ivar[4] * sin(dvar[6] + 2.0943951024) + result[ivar[6]][cols - 1] * sin(dvar[6] - 2.0943951024) + ivar[8];
	draw_line(dvar[3],dvar[0],dvar[4],dvar[1]);
}

void	draw_lines(int **result, int lines, int cols)
{
	double	dvar[7];
	int			ivar[11];

	dvar[6] = 5.235987756; // alfa
	ivar[10] = 0; // ver
	ivar[6] = 1; // i
	ivar[8] = 270; // sum
	ivar[9] = 1; // zoom
	while (ivar[6] <= lines - 1)
	{
		ivar[7] = 1;
		while (ivar[7] <= cols - 1)
		{
			draw_body(dvar, ivar, result);
			if (ivar[10] == 0)
				draw_horizont(dvar, ivar, result, lines);
			ivar[7]++;
		}
		ivar[10] = 1;
		draw_vertical(dvar, ivar, result, cols);
		ivar[6]++;
	}
}
