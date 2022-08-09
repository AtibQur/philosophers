/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/08/09 12:40:54 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
	return (0);
}
