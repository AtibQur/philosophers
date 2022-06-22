/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:05:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/22 15:06:32 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philosophers(int argc, char **argv)
{
	if (!check_input_errors(argv))
		return (0);
	init_philos(argc, argv);
	return (1);
}
