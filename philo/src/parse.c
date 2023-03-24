/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/24 11:23:42 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate(char *element)
{
	int	i;
	int	digit_found;

	i = 0;
	digit_found = 0;
	if (element[i] == '-')
		return (4);
	if (ft_strlen(element) > 9)
		return (3);
	if (element[i] == '+')
		i++;
	while (element[i] != '\0')
	{
		if (element[i] < '0' || element[i] > '9')
			return (2);
		else
			digit_found = 1;
		i++;
	}
	if (digit_found == 0)
		return (2);
	return (0);
}

static int	init_param(char **argv, int argc, t_param *param)
{
	if (ft_atoi(argv[1]) == 0)
	{
		error_message (5);
		return (FAIL);
	}
	param->number_of_philo = ft_atoi(argv[1]);
	param->time.hungry_time = ft_atoi(argv[2]);
	param->time.eating_time = ft_atoi(argv[3]);
	param->time.sleeping_time = ft_atoi(argv[4]);
	param->all_created = 0;
	param->death.index = 0;
	if (argc == 6)
	{
		param->must_eat = ft_atoi(argv[5]);
		if (param->must_eat == 0)
		{
			printf("All Philosophers ate at least 0 times\n");
			return (FAIL);
		}
	}
	else
		param->eaten_enough = 0;
	if (pthread_mutex_init(&param->mutex, NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	parse(int argc, char **argv, t_param *param)
{
	int		i;
	int		error_code;
	int		status;

	i = 0;
	status = FAIL;
	if (argc == 5 || argc == 6)
	{
		status = SUCCESS;
		while (++i < argc)
		{
			error_code = validate(argv[i]);
			if (error_code != 0)
			{
				error_message(error_code);
				status = FAIL;
			}
		}
	}
	else
		error_message(1);
	if (status == SUCCESS)
		status = init_param(argv, argc, param);
	return (status);
}
