/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:31:02 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/07 17:07:53 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnew(size_t size)
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		result[i++] = '\0';
	return (result);
}
