/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/24 10:01:15 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alloc_fail(void)
{
	printf("Memory allocation faild on your computer! try again later.\n");
}

void	error_message(int error_code)
{
	printf("\n ERROR \n");
	if (error_code == 1)
		printf("Too many or too few arguments. try with 4 or 5 arguments.\n");
	if (error_code == 2)
		printf("Arguments must be numbers and numbers only.\n");
	if (error_code == 3)
		printf("Too big numbers are frowned upon. Try sensable numbers.\n");
	if (error_code == 4)
		printf("Negative numbers are not valid input. Pass positive numbers.\n");
	if (error_code == 5)
	{
		printf("There should be one or more philosophers. Zero philosophers\n");
		printf(" is invalid input.\n");
	}
	if (error_code == 6)
		printf("Creation of threads failed on your computer. try again later.");
	if (error_code >= 1 && error_code <= 5)
	{
		printf("\n\n-------Here's a guide for the arguments-------\n");
		printf("Pass four mandatory arguments in this order: \n");
		printf("Number_of_philosophers time_to_die time_to_eat time_to_sleep\n");
		printf("And one optional :[number_of_times_each_philosopher_must_eat]");
	}
	printf("\n\n");
}
