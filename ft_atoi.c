/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:15:45 by ddulgher          #+#    #+#             */
/*   Updated: 2016/11/01 16:15:50 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int positive;

	positive = 1;
	n = 0;
	while (*str == ' ' || (unsigned)*str - '\t' < 5)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive = 0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 - (*str - '0');
		str++;
	}
	if (positive)
		return (-n);
	else
		return (n);
}
