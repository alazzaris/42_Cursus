/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:22:15 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 19:24:54 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h""

void ft_exit(t_structs *str, char *error_message, int status)
{
    free(str->a.stack);
    free(str->b.stack);
    write(1, error_message, ft_strlen(error_message));
    exit(status);
}

void ft_sort(t_structs *str)
{
    if()
}