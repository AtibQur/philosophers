/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:28:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/22 14:36:04 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_philosophers(t_data *data)
{
	t_data	*test;

	test = data;
	printf("yo--\n");
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
