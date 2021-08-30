/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:58 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/30 12:41:07 by mqueguin         ###   ########.fr       */
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

int	ft_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '-' || str[i] == '+')
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
	return (1);
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
		if (!ft_check(str))
		{
			free(str);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		result = ft_split(str, ' ');
		free(str);
	}
	else
		result = ft_split(av[1], ' ');
	return (result);
}

static	int	ft_fill_stack(char **result, t_stack *a, t_stack *b)
{
	int	i;

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
	return (1);
}

int	ft_split_arg(char **av, int ac, t_stack *a, t_stack *b)
{
	int		i;
	char	**result;

	result = ft_join_and_split(av, ac);
	if (result == NULL)
		return (0);
	i = -1;
	while (result[++i])
	{
		if (!ft_isdigit(result[i]))
		{
			ft_free(result);
			return (ft_putendl_fd("Error", 2));
		}
	}
	a = new_stack(i);
	b = new_stack(i);
	b->len = 0;
	if (!ft_fill_stack(result, a, b))
		return (0);
	ft_free(result);
	resolve(a, b);
	return (1);
}
