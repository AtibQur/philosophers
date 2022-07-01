/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:05:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/01 12:47:48 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating_info(t_data *data, int philo_id, char *string)
{
	// t_data	*temp;

	// temp = data;
	pthread_mutex_lock(&data->state);
	printf("Philo %d %s\n", philo_id + 1, string);
	pthread_mutex_unlock(&data->state);
}

void	eating(t_philos *philos)
{
	t_data	*data;

	data = philos->data;
	// printf("philo id-> %d\n", philos->philo_id);
	pthread_mutex_lock(&data->forks[philos->left_fork]);
	// eating_info(data, philos->philo_id, "grabbed a fork");
	pthread_mutex_lock(&data->forks[philos->right_fork]);
	// eating_info(data, philos->philo_id, "grabbed a fork");
	// pthread_mutex_unlock(&data->forks[philos->left_fork]);
	// pthread_mutex_unlock(&data->forks[philos->right_fork]);
}

void	*start_game(void *arg)
{
	t_philos	*philos;
	t_data		*data;
	int			i;

	i = 0;
	philos = arg;
	data = philos->data;
	// if (philos->philo_id % 2)
	// 	usleep(500);
	while (i < 1)
	{
		eating(philos);
		i++;
	}
	printf("-----\n");
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
		pthread_create(&philos[i].tid, NULL, start_game, &philos[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philos[i].tid, NULL) != 0)
			return (0);
		i++;
	}
	//check if everyone ate and if no one died.
	// free everytyhing
	return (1);
}
