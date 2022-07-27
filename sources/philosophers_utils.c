/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:48:26 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/27 13:02:37 by hqureshi         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
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

char	*action_color(int philo_id)
{
	if (philo_id % 3 == 1)
		return (GREEN);
	if (philo_id % 3 == 2)
		return (BLUE);
	if (philo_id % 3 == 3)
		return (CYAN);
	else
		return (PURPLE);
}
