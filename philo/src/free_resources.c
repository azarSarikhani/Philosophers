/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 13:45:44 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_double_pointer(void **pointer, int size)
{
	int		i;

	i = 0;
	if (!pointer)
		return ;
	while (i <= size)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

static void	destroy_mutex(t_mutex **forks)
{
	while (*forks)
	{
		pthread_mutex_destroy(*forks);
		forks++;
	}
}

void	free_fork(t_mutex **forks, int size)
{
	destroy_mutex(forks);
	free_double_pointer((void **)forks, size);
}

void	free_philos(t_philo	**philos)
{
	int	size;

	size = (*(philos))->param->number_of_philo;
	free_double_pointer((void **)philos, size);
}

void	free_structures(t_philo	**philos, t_mutex **forks)
{
	int	size;

	size = (*(philos))->param->number_of_philo;
	free_fork(forks, size);
	free_philos(philos);
}
