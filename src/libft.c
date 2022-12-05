/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:30:14 by coder             #+#    #+#             */
/*   Updated: 2022/11/14 02:16:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*pointer;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pointer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(pointer))
		return (NULL);
	while (s1[a])
	{
		pointer[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		pointer[a] = s2[b];
		b++;
		a++;
	}
	pointer[a] = '\0';
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;

	if (c == 0)
	{
		a = 0;
		while (s[a])
			a++;
		return ((char *)s + a);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (a < len && haystack[a])
	{
		if (haystack[a] == needle[b])
		{
			while (haystack[a] == needle[b] && a < len)
			{
				a++;
				b++;
				if (needle[b] == '\0')
					return (&((char *)haystack)[a - b]);
			}
			a = a - b;
			b = 0;
		}
		a++;
	}
	return (0);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)s)[a] = '\0';
		a++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}