/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 13:53:20 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_microsec	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	delta_time(t_microsec start_time, t_microsec now)
{
	t_microsec	delta;

	if (now == 0)
		now = get_time();
	delta = now - start_time;
	return (delta / 1000);
}

int	ms_sleep(long long ms, t_philo *philo)
{
	t_microsec	end;

	end = get_time() + (ms * 1000);
	while (get_time() < end)
	{
		if (someone_died(philo->param))
		{
			pthread_mutex_unlock(philo->hand.left);
			pthread_mutex_unlock(philo->hand.right);
			return (FAIL);
		}
		usleep(500);
	}
	return (SUCCESS);
}
