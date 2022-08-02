/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:05:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/02 14:42:52 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	thread_join(t_data *data, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philos[i].tid, NULL) != 0)
			return (0);
		i++;
	}
	return (0);
}

void	eating(t_philos *philos)
{
	t_data	*data;

	data = philos->data;
	pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
	action_info(data, philos->philo_id, "grabbed a fork");
	pthread_mutex_lock(&philos->data->forks[philos->right_fork]);
	action_info(data, philos->philo_id, "grabbed a fork");
	pthread_mutex_lock(&data->meal_time);
	philos->last_meal_time = timestamp();
	pthread_mutex_unlock(&data->meal_time);
	action_info(data, philos->philo_id, "is eating");
	timestamp_usleep(data->time_to_eat);
	philos->numbers_of_time_eaten--;
	pthread_mutex_unlock(&data->forks[philos->left_fork]);
	pthread_mutex_unlock(&data->forks[philos->right_fork]);
}

void	*start_game(void *arg)
{
	t_philos	*philos;
	t_data		*data;

	philos = arg;
	data = philos->data;
	if (data->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
		action_info(data, philos->philo_id, "grabbed a fork");
		return (NULL);
	}
	if (philos->philo_id % 2)
		timestamp_usleep(data->time_to_eat);
	while (check_status(data) != 1 && philos->numbers_of_time_eaten != 0)
	{
		eating(philos);
		action_info(data, philos->philo_id, "is sleeping");
		timestamp_usleep(data->time_to_sleep);
		action_info(data, philos->philo_id, "is thinking");
	}
	return (NULL);
}

int	philosophers(t_data *data)
{
	int			i;
	t_philos	*philos;

	i = 0;
	philos = data->philos;
	while (i < data->number_of_philosophers)
	{
		philos[i].last_meal_time = timestamp();
		pthread_create(&philos[i].tid, NULL, start_game, &philos[i]);
		i++;
	}
	check_philosophers(data);
	thread_join(data, philos);
	return (1);
}
