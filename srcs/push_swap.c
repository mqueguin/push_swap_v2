/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:28:43 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/30 12:17:43 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_biggest_in_middle(t_stack *a)
{	
	if (a->num[0] < a->num[2])
	{
		printf("rra\n");
		reverse_rotate(a);
		printf("sa\n");
		swap(a);
	}
	else
	{
		printf("rra\n");
		reverse_rotate(a);
	}
}

void	sort_3_numbers(t_stack *a)
{
	if (a->num[0] > a->num[1] && a->num[1] > a->num[2])
	{
		printf("sa\n");
		swap(a);
		printf("rra\n");
		reverse_rotate(a);
	}
	else if (a->num[0] > a->num[1] && a->num[1] < a->num[2])
	{
		if (a->num[0] > a->num[2])
		{
			printf("ra\n");
			rotate(a);
		}
		else
		{
			printf("sa\n");
			swap(a);
		}
	}
	else if (a->num[0] < a->num[1] && a->num[1] > a->num[2])
		sort_biggest_in_middle(a);
}

void	resolve(t_stack *a, t_stack *b)
{
	if (a_is_sorted(a))
	{
		stack_del(&a);
		stack_del(&b);
		return ;
	}
	if (a->len > 3)
		radix_sort(a, b);
	else if (a->len <= 3)
	{
		if (a->len == 2)
		{
			if (a->num[0] > a->num[1])
			{
				printf("sa\n");
				swap(a);
			}
		}
		else
			sort_3_numbers(a);
	}
	stack_del(&a);
	stack_del(&b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (ac > 1)
		if (!ft_split_arg(av, ac, a, b))
			return (-1);
	return (0);
}
