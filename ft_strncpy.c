/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:29:12 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/07 17:07:41 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*temp;

	temp = dest;
	while (n > 0)
	{
		if (*src == '\0')
			break ;
		*temp = *src;
		temp++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*temp = '\0';
		temp++;
		n--;
	}
	return (dest);
}
