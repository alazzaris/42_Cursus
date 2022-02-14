/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:22:15 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 22:56:37 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h""

void ft_exit(t_structs *s, char *error_message, int status)
{
    free(s->a.stack);
    free(s->b.stack);
    write(1, error_message, ft_strlen(error_message));
    exit(status);
}

void ft_sort(t_structs *s)
{
    if(s->size <= 3)
        ft_three(s);
    else if(s->size <= 5)
        ft_five(s);
    else if(s->size <= 100)
        ft_hundreds(s, (float)s->size / 4);
}

int main(int argc, char **argv)
{
    t_structs   s;

    ft_stack(&s, argc - 1);
    ft_check(&s, argc, argv);
    if (ft_is_sort(s.a))
        ft_exit(&s, "", 0);
    ft_sort(&s);
    ft_exit(&s, "", 0);
    return (0);
}