/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:07:09 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 00:46:29 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	ft_error_map_border(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_BORDER", 1);
	exit(ERROR_MAP_BORDER);
}

void	ft_error_map_player(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_PLAYER", 1);
	exit(ERROR_MAP_PLAYER);
}

void	ft_error_map_exit(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_EXIT", 1);
	exit(ERROR_MAP_WIDTH);
}

void	ft_error_map_found_forbidden_object(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_FOUND_FORBIDDEN_OBJECT", 1);
	exit(ERROR_MAP_FOUND_FORBIDDEN_OBJECT);
}
