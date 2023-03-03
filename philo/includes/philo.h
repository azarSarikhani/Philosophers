/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/03 14:55:09 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef pthread_mutex_t			t_mutex;
typedef pthread_t				t_pthread;
typedef unsigned long long int	t_microsec;

typedef struct s_time
{
	t_microsec	start_time;
	int			hungry_time;
	int			eating_time;
	int			sleeping_time;
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

typedef struct s_pram
{
	int		number_of_philo;
	int		eaten_enough;
	t_died	died;
	t_time	time;
}				t_pram;

typedef struct s_philo
{
	int			index;
	int			meal_count;
	t_hand		hand;
	t_pthread	thread;
	t_pram		*pram;
}				t_philo;

void	validate(int argc, char **argv);
#endif