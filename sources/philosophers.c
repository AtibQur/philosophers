/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:05:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 16:40:30 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philosophers(char **argv)
{
	t_data	*data;

	if (!check_input_errors(argv))
		return (0);
	data = init_philos(argv);
	if (!data)
	{
		free(data);
		return (0);
	}
	// else
	// 	start_philos(data);
	return (1);
}
