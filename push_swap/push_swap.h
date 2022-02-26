/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:41:59 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/26 01:10:25 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				flag;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_info
{
	int				number_a;
	int				number_b;
	int				max_pos;
	int				max_len;
	int				min_index;
	int				count;
	int				err;
}					t_info;

t_stack				*ft_element(t_info **info);
int					ft_split(t_stack **first_a, char *s, int *i, t_info **info);
int					ft_a(t_stack **first_a, char *s, int *i, t_info **info);
int					ft_number(char *s, t_stack *ps);
void				ft_index(t_stack *element, int curr_index, int curr_number);
int					ft_longest(t_stack **element, t_info **info,
						int *array, int max);
int					ft_best_index(t_stack *element, t_info *info);
int					ft_b(t_stack **first_a, t_stack **first_b, t_info **info);
int					ft_get_index(t_stack *lst_a, t_stack *lst_b, t_info *info);
int					ft_find_position(t_stack *lst, int index, t_info *info);
int					ft_back(t_stack **a, t_stack **b, t_info **info);
int					ft_bring(t_stack **element, int index, t_info **info,
						int a);
int					ft_move_both(t_stack **a, t_stack **b, int a_up, int b_up);
int					ft_swap(t_stack **element, int a);
int					ft_rotate(t_stack **element, int a);
int					ft_reverse_rotate(t_stack **element, int a);
int					ft_push(t_stack **src, t_stack **dst, int a);
int					ft_bigger(int a, int *b);
int					ft_smaller(int a, int *b);
int					ft_sign(int a);
int					ft_move_up(t_stack *lst, int index);
int					ft_move(int a, int b);
int					ft_free(t_stack **s, t_info **info);

#endif
