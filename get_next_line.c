/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:03:05 by ddulgher          #+#    #+#             */
/*   Updated: 2017/01/27 13:25:26 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	t_list		*head;

	FFD;
	PPD;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (pfd != fd && !(var[0] = 0))
	{
		pfd = fd;
		while (var[0] < BUFF_SIZE)
			buff[var[0]++] = 0;
		var[0] = 0;
	}
	if ((var[0] == 0 || NND || var[0] == var[2]) && !(var[0] = 0))
		var[2] = read(fd, buff, BUFF_SIZE);
	if (var[2] == 0 || var[2] < 0)
		return (var[2]);
	head = (t_list*)malloc(sizeof(t_list));
	head->chr = -1;
	ft_c(&buff, &var, head, fd);
	fill_the_str(head, var, line, buff);
	if (buff[var[0]] == '\n')
		var[0]++;
	var[1] = 0;
	delete_nodes(head);
	return (1);
}

void	ft_c(char (*b)[BUFF_SIZE], int (*v)[3], t_list *head, int fd)
{
	while ((*b)[(*v)[0]] != '\n' && (*b)[(*v)[0]] != '\0' && (*v)[0] < (*v)[2])
	{
		add_new_node((*b)[(*v)[0]], head);
		(*v)[0] = (*v)[0] + 1;
		(*v)[1] = (*v)[1] + 1;
	}
	if ((*v)[0] == BUFF_SIZE && !((*v)[0] = 0))
	{
		(*v)[2] = read(fd, *b, BUFF_SIZE);
		ft_c(b, v, head, fd);
	}
}

void	delete_nodes(t_list *head)
{
	t_list *current;
	t_list *temp;

	current = head;
	while (current->next != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	head = NULL;
}

void	fill_the_str(t_list *head, int var[3], char **line, char *buff)
{
	t_list	*current;
	int		crw;

	if (buff[var[0]] == '\n' && var[1] == 0)
	{
		*line = (char*)malloc(sizeof(char));
		(*line)[0] = '\0';
		return ;
	}
	current = head;
	crw = 0;
	*line = (char*)malloc(sizeof(char) * var[1] + 1);
	while (current->next != NULL)
	{
		(*line)[crw] = current->chr;
		current = current->next;
		crw++;
	}
	(*line)[crw++] = current->chr;
	(*line)[crw] = '\0';
}

void	add_new_node(char val, t_list *head)
{
	t_list	*new_node;
	t_list	*current;

	if (head->chr == -1)
	{
		head->chr = val;
		head->next = NULL;
		return ;
	}
	new_node = (t_list*)malloc(sizeof(t_list));
	new_node->chr = val;
	new_node->next = NULL;
	if (head->next == NULL)
		head->next = new_node;
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
