/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:37:51 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/28 16:27:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *copy)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < copy->len - 1)
	{
		if (copy->num[i] > copy->num[i + 1])
		{
			tmp = copy->num[i];
			copy->num[i] = copy->num[i + 1];
			copy->num[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	move_to_stack_b(t_stack *a, t_stack *b, int i)
{
	if (((a->num[0] >> i) & 1) == 1)
	{
		printf("ra\n");
		rotate(a);
	}
	else
	{
		printf("pb\n");
		push(b, a);
	}
}

void	sort_a_b(t_stack *a, t_stack *b)
{
	int		size;
	int		max_num;
	int		i;
	int		j;

	size = a->len;
	max_num = size - 1;
	i = 0;
	while (!a_is_sorted(a))
	{
		j = -1;
		while (++j < size)
			move_to_stack_b(a, b, i);
		while (b->len > 0)
		{
			printf("pa\n");
			push(a, b);
		}
		i++;
	}
}

static	void	fill_and_sort_copy(t_stack *copy, t_stack *a)
{
	int		i;

	i = -1;
	while (++i < a->len)
		copy->num[i] = a->num[i];
	sort(copy);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	t_stack		*copy;

	copy = new_stack(a->len);
	fill_and_sort_copy(copy, a);
	i = -1;
	while (++i < a->len)
	{
		j = -1;
		while (++j < copy->len)
		{
			if (a->num[i] == copy->num[j])
			{
				a->num[i] = j;
				break ;
			}
		}
	}
	if (a->len == 5)
		sort_5_numbers(a, b, -1, get_pivot(a));
	else
		sort_a_b(a, b);
	stack_del(&copy);
}
