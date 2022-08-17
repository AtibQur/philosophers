/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/17 10:07:20 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// Check for leaks in the whole program with atexit();
// void	check_leaks()
// {
// 	system ("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!init_program(&data, argv))
		{
			write_instructions(1);
			return (1);
		}
	}
	else if (argc < 5 || argc > 6)
	{
		write_instructions(2);
		return (1);
	}
	// atexit(check_leaks);
	return (0);
}
