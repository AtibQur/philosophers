/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:31:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 12:33:41 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// there should always be 1 philo, and not more than 200.
// there should be atleast some time between dying, eating, sleeping.
static int	check_input_numbers(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || \
		ft_atoi(argv[1]) > 200 || \
		ft_atoi(argv[2]) < 0 || \
		ft_atoi(argv[3]) < 0 || \
		ft_atoi(argv[4]) < 0)
		return (0);
	return (1);
}

int	check_input_errors(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || !ft_iswhitespaces(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_input_numbers(argv))
		return (0);
	return (1);
}
