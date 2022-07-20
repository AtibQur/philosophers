/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:48:26 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/20 12:30:53 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	write_instructions(int error_message)
{
	if (error_message == 1)
	{
		write(2, "Error, arguments should only exist of numbers\n", 47);
		write(2, "There should be between 1 or 200 philosophers ", 47);
		write(2, "and some time to die, eat and sleep.\n", 38);
	}
	if (error_message == 2)
		write(2, "Error. Choose a amount arguments between 4 or 5\n", 49);
	if (error_message == 3)
		write(2, "Error. Choose a correct amount for the philosophers to eat\n", \
		60);
	return (1);
}

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

void	timestamp_usleep(long time)
{
	long	current_time;

	current_time = timestamp();
	while (timestamp() < current_time + time)
		usleep(time);
}

long	timestamp(void)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (milliseconds);
}
