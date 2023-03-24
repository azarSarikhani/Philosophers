/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/24 09:54:46 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	first = philo->hand.left;
	second = philo->hand.right;
	pthread_mutex_lock(first);
	print("has taken a fork\n", philo);
	pthread_mutex_lock(second);
	philo->last_meal = get_time();
	print("has taken a fork\n", philo);
}

int	eating(t_philo *philo)
{
	if (someone_died(philo->param) || all_eaten_enough(philo))
		return (0);
	take_forks(philo);
	print("is eating\n", philo);
	if (ms_sleep(philo->param->time.eating_time, philo) == FAIL)
		return (FAIL);
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
	philo->meal_count++;
	if (philo->meal_count == philo->param->must_eat)
	{
		pthread_mutex_lock(&(philo)->param->mutex);
		philo->param->eaten_enough++;
		pthread_mutex_unlock(&(philo)->param->mutex);
	}
	return (SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (someone_died(philo->param) || all_eaten_enough(philo))
		return (FAIL);
	print("is thinking\n", philo);
	return (SUCCESS);
}

int	sleeping(t_philo *philo)
{
	if (someone_died(philo->param) || all_eaten_enough(philo))
		return (0);
	print("is sleeping\n", philo);
	if (ms_sleep(philo->param->time.sleeping_time, philo) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->param->all_created != SUCCESS)
		continue ;
	philo->last_meal = philo->param->time.start_time;
	printf("%d %d is thinking\n",
		delta_time(philo->param->time.start_time, 0), philo->index);
	if (philo->index % 2 == 0)
		ms_sleep(philo->param->time.eating_time, philo);
	while (eating(philo) && sleeping(philo) && thinking(philo))
		continue ;
	return (arg);
}
