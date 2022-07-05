/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:58:30 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 00:43:53 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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
