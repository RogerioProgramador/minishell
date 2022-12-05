/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:48:15 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/11/14 02:16:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1000

typedef struct s_mini
{
	char				*command;
	char				**flags;
	char				**parameters;
	unsigned long		hasPipe;
	unsigned long		hasRedirect;
	unsigned long		hasReverseRedirect;
	unsigned long		hasDoubleRedirect;
	unsigned long		hasDoubleReverseRedirect;
}	t_mini;

// typedef struct s_push
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	size_t	stack_size_a;
// 	size_t	stack_size_b;
// }	t_push;

/* UTILS */

void	print_string(char *s);
void	print_string_len(char *s, int len); //UTIL? PODE APAGAR SE N FOR



/* LIBFT */
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);

#endif
