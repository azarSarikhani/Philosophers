/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 13:46:19 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	initialize_forks(t_mutex **forks, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		forks[i] = malloc(sizeof(t_mutex));
		if (!forks[i])
		{
			while (--i >= 0)
			{
				free(forks[i]);
			}
			return (FAIL);
		}
	}
	i = -1;
	while ((forks)[++i])
	{
		pthread_mutex_init((forks)[i], NULL);
	}
	return (SUCCESS);
}

int	create_forks(t_mutex ***forks, int size)
{
	*forks = malloc(sizeof(t_mutex *) * (size + 1));
	if (!*forks)
		return (FAIL);
	(*forks)[size] = NULL;
	if (initialize_forks(*forks, size) == FAIL)
	{
		free(*forks);
		alloc_fail();
		return (FAIL);
	}
	return (SUCCESS);
}

static void	set_hands(t_philo *philo, t_mutex **forks)
{
	philo->hand.left = forks[philo->index - 1];
	philo->hand.right = forks[philo->index];
	if (philo->hand.right == NULL)
		philo->hand.right = forks[0];
}

static int	initialize_philos(t_philo **philos, t_mutex **forks, t_param *param,
		int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			while (--i >= 0)
			{
				free(philos[i]);
			}
			return (FAIL);
		}
	}
	i = -1;
	while (++i < size)
	{
		philos[i]->index = i + 1;
		philos[i]->meal_count = 0;
		philos[i]->param = param;
		set_hands(philos[i], forks);
	}
	return (SUCCESS);
}

int	create_philos(t_philo ***philos, t_mutex **forks, t_param *param, int size)
{
	*philos = malloc(sizeof(t_philo *) * (size + 1));
	if (!*philos)
		return (FAIL);
	(*philos)[size] = NULL;
	if (initialize_philos(*philos, forks, param, size) == FAIL)
	{
		free (*philos);
		alloc_fail();
		return (FAIL);
	}
	return (SUCCESS);
}
