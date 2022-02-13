/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:36:35 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/13 19:21:49 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_chunk
{
	unsigned int	min;
	unsigned int	max;
	int				mid;
}	t_chunk;

typedef struct s_stack
{
	int				*stack;
	unsigned int	size;		
}	t_stack;

typedef struct s_struct
{
	t_stack			a;
	t_stack			b;
	unsigned int	size;
}	t_struct;

#endif