/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:58:28 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 00:43:53 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_error_map_not_found(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_FOUND", 1);
	exit(ERROR_MAP_NOT_FOUND);
}

void	ft_error_map_not_valid(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_VALID", 1);
	exit(ERROR_MAP_NOT_VALID);
}

void	ft_error_map_not_ber_extention(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_BER_EXTENTION", 1);
	exit(ERROR_MAP_NOT_BER_EXTENTION);
}

void	ft_error_game_is_null(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_GAME_IS_NULL", 1);
	exit(ERROR_GAME_IS_NULL);
}

void	ft_error_map_width(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_WIDTH", 1);
	exit(ERROR_MAP_WIDTH);
}
