/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavina <msavina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:18:37 by msavina           #+#    #+#             */
/*   Updated: 2023/11/17 19:04:30 by msavina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(size * count);
	if (mem == NULL)
		return (NULL);
	while (i < count)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1 && s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	ft_strchr(char *str, char c)
{
	int	i;
	int	len;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	if (!s)
		return (0);
	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}

void	*ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
