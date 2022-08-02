/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:28:46 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/02 14:21:54 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* data->number_of_philosophers);
	if (!data->forks)
		return (0);
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->state, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->status, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->meal_time, NULL) != 0)
		return (0);
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = NULL;
	data->philos = (t_philos *)malloc(sizeof(*(data->philos)) * \
	data->number_of_philosophers);
	if (!data->philos)
		return (0);
	while (i < data->number_of_philosophers)
	{
		data->philos[i].philo_id = i;
		data->philos[i].numbers_of_time_eaten = data->number_of_times_to_eat;
		data->philos[i].left_fork = i;
		if (i + 1 == data->number_of_philosophers)
			data->philos[i].right_fork = 0;
		else
			data->philos[i].right_fork = i + 1;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	init_program(t_data *data, char **argv)
{
	if (!check_input_errors(argv))
		return (0);
	data->finished = false;
	data->philo_died = false;
	data->start_time = timestamp();
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->number_of_times_to_eat = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) <= 0)
			return (write_instructions(3));
	}
	else
		data->number_of_times_to_eat = -1;
	init_philos(data);
	if (!init_mutexes(data))
		return (0);
	if (!philosophers(data))
		return (0);
	return (1);
}
