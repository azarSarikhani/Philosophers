/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/24 11:22:59 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define FAIL 0
# define SUCCESS 1

# define TRUE 1
# define FALSE 0

typedef pthread_mutex_t			t_mutex;
typedef pthread_t				t_pthread;
typedef unsigned long long int	t_microsec;

typedef struct s_time
{
	t_microsec	start_time;
	long long	hungry_time;
	long long	eating_time;
	long long	sleeping_time;
}				t_time;

typedef struct s_hand
{
	t_mutex	*left;
	t_mutex	*right;
}				t_hand;

typedef struct s_died
{
	t_mutex		mutex;
	int			index;
	t_microsec	time;
}				t_died;

typedef struct s_param
{
	t_mutex		mutex;
	int			all_created;
	int			number_of_philo;
	int			must_eat;
	int			eaten_enough;
	t_died		death;
	t_time		time;
}				t_param;

typedef struct s_philo
{
	int			index;
	int			eaten_enough;
	int			meal_count;
	t_microsec	last_meal;
	t_hand		hand;
	t_pthread	thread;
	t_param		*param;
}				t_philo;

int			parse(int argc, char **argv, t_param *param);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
void		error_message(int error_msg);
void		alloc_fail(void);
int			create_forks(t_mutex ***forks, int size);
int			create_philo_threads(t_philo **philo);
void		free_fork(t_mutex **forks, int size);
void		free_philos(t_philo	**philos);
void		free_structures(t_philo	**philos, t_mutex **forks);
int			start_routines(t_philo **philos, t_microsec *start_time);
void		*routine(void *arg);
int			create_philos(t_philo ***philos, t_mutex **forks, t_param *param,
				int size);
t_microsec	get_time(void);
int			ms_sleep(long long ms, t_philo *philo);
int			delta_time(t_microsec init, t_microsec now);
void		join_philo_threads(t_philo **philos);
int			someone_died(t_param *param);
int			all_eaten_enough(t_philo *philo);
void		print_eaten_enough(t_philo *philos);
void		print_death(t_param param);
void		print(char *message, t_philo *philo);

#endif