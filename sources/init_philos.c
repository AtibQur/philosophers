/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:28:46 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/22 15:14:30 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philos(int argc, char **argv)
{
	t_data	*data;

	// data = calloc(data, sizeof(data));
	data->philos->number_of_philosophers = ft_atoi(argv[1]);
	data->philos->time_to_die = ft_atoi(argv[2]);
	data->philos->time_to_eat= ft_atoi(argv[3]);
	data->philos->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->philos->number_of_times_to_eat = ft_atoi(argv[5]);
}

/* 
arg[1] number_of_philosophers 
arg[2] time_to_die 
arg[3] time_to_eat
arg[4] time_to_sleep
arg[5] [number_of_times_each_philosopher_must_eat]  --> optional
*/
