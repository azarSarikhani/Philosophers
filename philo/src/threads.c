/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 13:53:02 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo **philos)
{
	t_pthread	thread;
	int			i;
	int			size;

	i = -1;
	size = (*(philos))->param->number_of_philo;
	while (++i < size)
	{
		if (pthread_create(&thread, NULL, &routine, (void *)philos[i]) != 0)
			return (FAIL);
		(philos[i])->thread = thread;
	}
	return (SUCCESS);
}

void	join_philo_threads(t_philo **philos)
{
	int			i;
	int			size;

	i = -1;
	size = (*(philos))->param->number_of_philo;
	while (++i < size)
	{
		pthread_join((philos[i])->thread, NULL);
	}
}

int	start_routines(t_philo **philos, t_microsec *start_time)
{
	if (create_philo_threads(philos) == FAIL)
	{
		error_message (6);
		return (FAIL);
	}
	*start_time = get_time();
	(*(philos))->param->all_created = SUCCESS;
	return (SUCCESS);
}
