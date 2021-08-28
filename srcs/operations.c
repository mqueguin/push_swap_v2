/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:04:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/28 16:27:40 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->num[stack->len - 1];
	i = stack->len - 1;
	while (i >= 1)
	{
		stack->num[i] = stack->num[i - 1];
		i--;
	}
	stack->num[0] = tmp;
}

void	rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->num[0];
	i = 0;
	while (i + 1 < stack->len)
	{
		stack->num[i] = stack->num[i + 1];
		i++;
	}
	stack->num[i] = tmp;
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = stack_a->len - 1;
	while (i >= 0)
	{
		stack_a->num[i + 1] = stack_a->num[i];
		i--;
	}
	stack_a->num[0] = stack_b->num[0];
	i = 0;
	while (i < stack_b->len - 1)
	{
		stack_b->num[i] = stack_b->num[i + 1];
		i++;
	}
	stack_a->len++;
	stack_b->len--;
}

void	swap(t_stack *stack)
{
	int		tmp;

	tmp = stack->num[0];
	stack->num[0] = stack->num[1];
	stack->num[1] = tmp;
}
