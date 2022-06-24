/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:46:49 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 11:34:07 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_iswhitespaces(int s)
{
	if (s == 32 || s == 9 || s == 10 || s == 11)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	result;

	i = 0;
	min = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str != '\0' && *str == '-')
	{
		min = -1;
		str++;
	}
	else if (*str == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (i > 10 && min == -1)
			return (0);
		if (i > 10)
			return (-1);
	}
	return (result * min);
}
