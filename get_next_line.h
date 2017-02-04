/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:03:11 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/04 20:29:04 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define FFD static int pfd = -1
# define PPD static int var[3]
# define NND var[0] == BUFF_SIZE

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			chr;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

void				fill_the_str(t_list *head, int v[3], char **line, char *b);

void				add_new_node(char val, t_list *head);

void				delete_nodes(t_list *head);

void				ft_c(char (*b)[BUFF_SIZE], int (*v)[3], t_list *h, int fd);

#endif
