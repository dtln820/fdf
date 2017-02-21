CC = gcc
CFLAGS = -Werror -Wall -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fdf

$(NAME): drawing_help.o drawing_help2.o ft_atoi.o ft_putstr.o ft_strncpy.o ft_strnew.o ft_strsplit.o get_next_line.o main.o
	$(CC) $(CFLAGS) drawing_help.o drawing_help2.o ft_putstr.o ft_strncpy.o ft_strnew.o ft_atoi.o ft_strsplit.o get_next_line.o main.o -o fdf $(MLXFLAGS)

all: $(NAME)

drawing_help.o: drawing_help.c fdf.h
	$(CC) $(CFLAGS) -c drawing_help.c -o drawing_help.o

drawing_help2.o: drawing_help2.c fdf.h
	$(CC) $(CFLAGS) -c drawing_help2.c -o drawing_help2.o

ft_putstr.o: ft_putstr.c fdf.h
	$(CC) $(CFLAGS) -c ft_putstr.c -o ft_putstr.o

ft_strncpy.o: ft_strncpy.c fdf.h
	$(CC) $(CFLAGS) -c ft_strncpy.c -o ft_strncpy.o

ft_strnew.o: ft_strnew.c fdf.h
	$(CC) $(CFLAGS) -c ft_strnew.c -o ft_strnew.o

ft_strsplit.o: ft_strsplit.c fdf.h
	$(CC) $(CFLAGS) -c ft_strsplit.c -o ft_strsplit.o

get_next_line.o: get_next_line.c fdf.h
	$(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o

ft_atoi.o: ft_atoi.c fdf.h
	$(CC) $(CFLAGS) -c ft_atoi.c -o ft_atoi.o

main.o: main.c fdf.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f drawing_help.o drawing_help2.o ft_putstr.o ft_strncpy.o ft_strnew.o ft_strsplit.o ft_atoi.o get_next_line.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all
