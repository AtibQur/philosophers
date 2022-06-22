/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/22 14:27:39 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!philosophers(argv))
		{
			printf("Error. Arguments should only exist of numbers.\n");
			return (EXIT_FAILURE);
		}
	}
	else if (argc < 5 || argc > 6)
	{
		printf("Error. Choose a amount arguments between 4 or 5\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
