/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 12:31:21 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	write_instructions(int error_message)
{
	if (error_message == 1)
	{
		write(1, "Error, arguments should only exist of numbers\n", 47);
		write(1, "There should be between 1 or 200 philosophers ", 47);
		write(1, "and some time to die, eat and sleep.\n", 38);
	}
	if (error_message == 2)
		write(1, "Error. Choose a amount arguments between 4 or 5\n", 49);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!philosophers(argv))
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
	return (0);
}
