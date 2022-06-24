/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:32 by hqureshi          #+#    #+#             */
/*   Updated: 2022/06/24 16:14:02 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct s_philos {
	int				philo_id;
	int				numbers_of_time_eaten;
	struct s_philos	*next;
}	t_philos;

typedef struct s_data {
	t_philos		*philos;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	bool			optional_nums_to_eat;
}	t_data;

int		main(int argc, char **argv);
int		philosophers(char **argv);
int		check_input_errors(char **argv);
int		ft_isdigit(int c);
int		ft_iswhitespaces(int s);
int		ft_atoi(const char *str);

t_data	*init_philos(char **argv);

#endif
