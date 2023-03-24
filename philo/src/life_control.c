/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/23 14:36:09 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_died(t_param *param)
{
	if (param->death.index != 0)
		return (TRUE);
	return (FALSE);
}

int	all_eaten_enough(t_philo *philo)
{
	if (philo->param->eaten_enough == philo->param->number_of_philo)
		return (TRUE);
	return (FALSE);
}
