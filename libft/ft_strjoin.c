/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:09:14 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/30 11:54:08 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, char const *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, char const *src)
{
	size_t	i;

	i = ft_strlen(dst) + 1;
	dst[i - 1] = ' ';
	while (*src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = ' ';
	dst[i + 1] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2, int b_free)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 3);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (b_free == 1)
	{
		free((void *)s1);
		s1 = NULL;
	}
	return (str);
}
