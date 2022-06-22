/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:32 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/22 15:08:41 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_philos
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	struct s_data	*next;
}	t_philos;


typedef struct s_data {
	t_philos	*philos;
}	t_data;


int		main(int argc, char **argv);
int		philosophers(int argc, char **argv);

int		check_input_errors(char **argv);
int		ft_isdigit(int c);
int		ft_iswhitespaces(int s);
int		ft_atoi(const char *str);
void	init_philos(int argc, char **argv);

#endif
