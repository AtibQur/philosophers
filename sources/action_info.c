/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:03:17 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/02 14:27:51 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	action_info(t_data *data, int philo_id, char *string)
{
	pthread_mutex_lock(&data->state);
	if (!ft_strncmp(string, "died", 4))
	{
		printf("%s%ld\t", RED, timestamp() - data->start_time);
		printf("Philosopher [%d] %s.%s\n", philo_id + 1, string, RESET);
		data->philo_died = true;
	}
	else
	{
		if (data->philo_died == false)
		{
			printf("%s%ld\t", action_color(philo_id), \
			timestamp() - data->start_time);
			printf("Philosopher [%d] %s.%s\n", philo_id + 1, string, RESET);
		}
	}
	pthread_mutex_unlock(&data->state);
}
