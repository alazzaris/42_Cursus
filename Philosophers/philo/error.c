/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:15:34 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/16 19:15:34 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_args_error(void)
{
	printf(".__________________________________.\n");
	printf("|         ERROR ARGUMENTS          |\n");
	printf("|     ./philo [1][2][3][4][5]      |\n");
	printf("|----------------------------------|\n");
	printf("|    [1] Number of Philosophers    |\n");
	printf("|----------------------------------|\n");
	printf("|    [2] Time to Die               |\n");
	printf("|----------------------------------|\n");
	printf("|    [3] Time to Eat               |\n");
	printf("|----------------------------------|\n");
	printf("|    [4] Time to Sleep             |\n");
	printf("|----------------------------------|\n");
	printf("|    [5] Number of times each      |\n");
	printf("|        Philosophers must eat     |\n");
	printf("|__________________________________|\n");
}
