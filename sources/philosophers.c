/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:05:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/01 14:23:28 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating_info(t_data *data, int philo_id, char *string)
{
	pthread_mutex_lock(&data->state);
	printf("Philo %d %s\n", philo_id + 1, string);
	pthread_mutex_unlock(&data->state);
}

void	eating(t_philos *philos)
{
	t_data	*data;

	data = philos->data;
	pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
	eating_info(data, philos->philo_id, "grabbed a fork");
	pthread_mutex_lock(&data->forks[philos->right_fork]);
	eating_info(data, philos->philo_id, "grabbed a fork");
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
	if (philos->philo_id % 2)
		usleep(500);
	while (check_status(data) != 1 && philos->numbers_of_time_eaten != 0)
	{
		printf("%d\n", philos->numbers_of_time_eaten);
		eating(philos);
	}
	printf("----------------\n");
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
