/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:28:46 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 16:39:33 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_philo_threads(t_data *data)
{
	t_philos	*philos;
	int			i;

	philos = malloc(sizeof(t_philos) * data->number_of_philosophers);
	if (!philos)
		return (0);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philos[i].philo_id = i + 1;
		philos[i].numbers_of_time_eaten = 0;
		i++;
	}
	data->philos = philos;
	return (1);
}

t_data	*init_philos(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->optional_nums_to_eat = false;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->number_of_times_to_eat = ft_atoi(argv[5]);
		data->optional_nums_to_eat = true;
	}
	if (!init_philo_threads(data))
		return (0);
	return (data);
}

/* 
arg[1] number_of_philosophers
arg[2] time_to_die
arg[3] time_to_eat
arg[4] time_to_sleep
arg[5] [number_of_times_each_philosopher_must_eat]  --> optional
*/
