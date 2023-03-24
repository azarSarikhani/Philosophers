/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 10:08:26 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *message, t_philo *philo)
{
	if (someone_died(philo->param) || all_eaten_enough(philo))
		return ;
	printf("%d %d %s",
		delta_time(philo->param->time.start_time, 0),
		philo->index,
		message);
}

void	print_death(t_param param)
{
	if (someone_died(&param))
		printf("%d %d died\n",
			delta_time(param.time.start_time, param.death.time),
			param.death.index);
	return ;
}

void	print_eaten_enough(t_philo *philos)
{
	if (all_eaten_enough(philos))
		printf("All Philosophers ate at least %d times\n",
			philos->param->must_eat);
	return ;
}
