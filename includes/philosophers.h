/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:32 by hqureshi          #+#    #+#             */
/*   Updated: 2022/07/22 13:41:24 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define PURPLE "\033[0;35m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos {
	pthread_t		tid;
	int				philo_id;
	int				numbers_of_time_eaten;
	int				left_fork;
	int				right_fork;
	struct s_data	*data;
}	t_philos;

typedef struct s_data {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_to_eat;
	bool				finished;
	long				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		state;
	pthread_mutex_t		status;
	t_philos			*philos;
}	t_data;

int		main(int argc, char **argv);
int		init_program(t_data *data, char **argv);
int		check_input_errors(char **argv);
int		ft_atoi(const char *str);
int		write_instructions(int error_message);
int		init_philos(t_data *data);
int		philosophers(t_data *data);
void	*start_game(void *arg);
int		check_status(t_data *data);
void	timestamp_usleep(long time);
long	timestamp(void);
char	*action_color(int philo_id);
void	action_info(t_data *data, int philo_id, char *string);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_philosophers(t_data *data);

#endif
