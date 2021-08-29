/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:58 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/28 19:04:13 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static char	**ft_join_and_split(char **av, int ac)
{
	int		i;
	char	*str;
	char	**result;

	if (ac > 2)
	{
		str = ft_strjoin(av[1], av[2], 0);
		i = 2;
		while (av[++i])
			str = ft_strjoin(str, av[i], 1);
		result = ft_split(str, ' ');
		free(str);
	}
	else
		result = ft_split(av[1], ' ');
	return (result);
}

int	ft_split_arg(char **av, int ac, t_stack *a, t_stack *b)
{
	int		i;
	char	**result;

	result = ft_join_and_split(av, ac);
	i = -1;
	while (result[++i])
		if (!ft_isdigit(result[i]))
		{
			ft_free(result);
			return (ft_putendl_fd("Error", 2));
		}
	a = new_stack(i);
	b = new_stack(i);
	b->len = 0;
	i = -1;
	while (result[++i])
	{
		if (has_double(result[i], a->num, i))
		{
			stack_del(&a);
			stack_del(&b);
			ft_free(result);
			return (ft_putendl_fd("Error", 2));
		}
		a->num[i] = ft_atoi(result[i]);
	}
	ft_free(result);
	resolve(a, b);
	return (1);
}
