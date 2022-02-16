/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:00:36 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/16 23:14:07 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk ft_chunk_one(t_structs *s, t_chunk chunk)
{
    chunk.min = chunk.max;
    if (!chunk.max)
        chunk.max = s->size / 2;
    else if (chunk.max < s->size - s->size / 32)
}