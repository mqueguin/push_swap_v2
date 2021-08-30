/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:23 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/30 12:15:29 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int len)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack->len = len;
	if (len > 0)
	{
		stack->num = (int *)malloc(sizeof(int) * len);
		if (stack->num == NULL)
		{
			ft_putendl_fd("Error", 2);
			exit (0);
		}
	}
	else
		stack->num = 0;
	return (stack);
}

void	stack_del(t_stack **stack)
{
	if (*stack)
	{
		free((*stack)->num);
		(*stack)->num = 0;
		free(*stack);
		*stack = 0;
	}
}
