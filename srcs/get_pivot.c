/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:34:26 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/28 16:27:21 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *stack_a)
{
	int	i;
	int	j;
	int	pivot;
	int	left;
	int	right;

	i = 0;
	left = 0;
	right = 1;
	while (left != right)
	{
		right = !(stack_a->len % 2);
		left = 0;
		pivot = stack_a->num[i];
		j = -1;
		while (++j < stack_a->len)
		{
			if (pivot < stack_a->num[j])
				right++;
			else if (pivot > stack_a->num[j])
				left++;
		}
		i++;
	}
	return (pivot);
}
