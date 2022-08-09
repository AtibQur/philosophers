/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:28:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/09 12:41:24 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_status(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->status);
	if (data->finished == true)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&data->status);
	return (ret);
}

void	change_status(t_data *data)
{
	pthread_mutex_lock(&data->status);
	data->finished = true;
	pthread_mutex_unlock(&data->status);
}

long	check_meal_times(t_philos *philos)
{
	long	meal_time;

	pthread_mutex_lock(&philos->data->meal_time);
	meal_time = philos->last_meal_time;
	pthread_mutex_unlock(&philos->data->meal_time);
	return (meal_time);
}

void	monitoring(t_data *data)
{
	int			i;
	long		last_meal;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		last_meal = timestamp() - check_meal_times(&data->philos[i]);
		if (data->time_to_die < last_meal)
		{
			change_status(data);
			if (data->philos[i].numbers_of_time_eaten != 0)
				action_info(data, i, "died");
			return ;
		}
		i++;
	}
}

void	check_philosophers(t_data *data)
{
	while (check_status(data) == 0)
		monitoring(data);
	free(data->forks);
	free(data->philos);
}
