/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:53:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/14 00:54:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_string(char *s)
{
	if (s == 0)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	print_string_len(char *s, int len)
{
	int i;

	i = 0;
	if (s == 0)
		return ;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

