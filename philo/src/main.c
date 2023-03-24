/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/24 11:34:53 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_structures(t_param *param, t_philo ***philos,
		t_mutex ***forks, int size)
{
	if (create_forks(forks, size))
	{
		if (create_philos(philos, *forks, param, size))
		{
			if (pthread_mutex_init(&param->death.mutex, NULL) == 0)
				return (SUCCESS);
			else
			{
				free_structures(*philos, *forks);
				return (FAIL);
			}
		}
		else
		{
			free_fork(*forks, size);
			return (FAIL);
		}
	}
	else
		return (FAIL);
}

int	life_control(t_philo **philo, int size)
{
	int	i;

	i = -1;
	while ((*(philo))->param->all_created != SUCCESS)
		continue ;
	usleep((philo[0]->param->time.hungry_time) * 1000);
	while (++i < size && !someone_died(philo[i]->param)
		&& !all_eaten_enough(*philo))
	{
		if ((philo[i]->param->time.hungry_time * 1000) + philo[i]->last_meal
			< get_time() + 5)
		{
			pthread_mutex_lock(&(*(philo))->param->death.mutex);
			(*(philo))->param->death.time = (philo[i]->param->time.hungry_time
					* 1000) + philo[i]->last_meal;
			(*(philo))->param->death.index = philo[i]->index;
			pthread_mutex_unlock(&(*(philo))->param->death.mutex);
			pthread_mutex_unlock(philo[i]->hand.left);
			pthread_mutex_unlock(philo[i]->hand.right);
			return (FALSE);
		}
		if (i == size - 1)
			i = -1;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_param	param;
	t_mutex	**forks;

	ft_bzero(&param, sizeof(t_param));
	philos = NULL;
	forks = NULL;
	if (parse(argc, argv, &param) == SUCCESS)
	{
		if (initialize_structures(&param, &philos, &forks,
				param.number_of_philo))
		{
			if (start_routines(philos, &param.time.start_time))
			{
				life_control(philos, param.number_of_philo);
				join_philo_threads(philos);
				print_death(param);
				print_eaten_enough(*philos);
			}
			free_structures(philos, forks);
		}
	}
	return (0);
}
