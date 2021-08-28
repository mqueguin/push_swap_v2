/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:54:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/28 16:28:00 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate_5_numbers(t_stack *a, int i)
{
	int		index;

	index = a->len - i;
	while (index > 0)
	{
		printf("rra\n");
		reverse_rotate(a);
		index--;
	}
}

static	void	sort_5_numbers_second_part(t_stack *a, t_stack *b)
{
	sort_3_numbers(a);
	if (b->num[0] < b->num[1])
	{
		printf("sb\n");
		swap(b);
	}
	while (b->len > 0)
	{
		printf("pa\n");
		push(a, b);
	}
}

void	sort_5_numbers(t_stack *a, t_stack *b, int i, int pivot)
{
	while (a->len > 3)
	{
		if (a->num[0] < pivot)
		{
			printf("pb\n");
			push(b, a);
		}
		else if (a->num[++i] < pivot)
		{
			if (i <= a->len - i)
			{
				while (i-- > 0)
				{
					printf("ra\n");
					rotate(a);
				}
			}
			else
				rotate_5_numbers(a, i);
		}
	}
	sort_5_numbers_second_part(a, b);
}
