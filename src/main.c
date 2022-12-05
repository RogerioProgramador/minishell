/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:49:58 by coder             #+#    #+#             */
/*   Updated: 2022/11/14 04:51:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	start() {
	print_string("\nWELCOME TO MY FUCKING MINISHELL\n\n");	
}

void	add_command(t_mini *command, char *buffer, int len)
{
	t_mini	*new_command;

	// echo $RATINHO '> r10.txt | grep RATINHO

	// chega: echo $RATINHO "Festa do $RATINHO" putz'n da pra ir to sem $CARRO'> r10.txt
	// splitar em " " 
	// fica:
	/*
		echo
		$RATINHO
		"Festa do $RATINHO"
		putz'n da pra ir to sem $CARRO'>
		r10.txt
	*/

	// 1 passo: substituir nas frases oq tem dolar SE NÃO ESTIVER ENTRE ASPAS "";
	// 2 passo: arg[0] vira commando, o resto vira parametro até chegar o redirect
	// 3 


	

	(void)command;
	print_string_len(buffer, len);
	print_string("\n");

	/*BOOLEANOS*/
	new_command->hasDoubleRedirect= (unsigned long)ft_strnstr(">>", buffer, len);
	new_command->hasReverseRedirect= (unsigned long)ft_strnstr("<<", buffer, len);
	if (new_command->hasDoubleRedirect)
		new_command->hasRedirect = 0;
	else
		new_command->hasRedirect = (unsigned long)ft_strnstr(">", buffer, len);
	if (new_command->hasDoubleReverseRedirect)
		new_command->hasReverseRedirect = 0;
	else
		new_command->hasReverseRedirect = (unsigned long)ft_strnstr("<", buffer, len);
}

t_mini	*parse(char *buffer)
{
	char	*pointer;
	char	*buffer_ref;
	t_mini	*commands;
	
	pointer = buffer;
	buffer_ref = buffer;
	// env | grep PWD
	while(buffer_ref)
	{
		pointer = ft_strchr(buffer_ref, '|');
		if (pointer)
			add_command(commands, buffer_ref, pointer - buffer_ref);
		else
		{
			add_command(commands, buffer_ref, ft_strlen(buffer_ref));
			break ;
		}
		buffer_ref = pointer + 1;
	}
}

/*loop.c*/
char	*current_path(void)
{	
	return (ft_strjoin(getenv("PWD"), "$ "));
}

void init_loop(char **buffer)
{
	t_mini *command;

	while(1)
	{
		*buffer = readline(current_path());
		command = parse(*buffer);
		// execute_commands(command);
		// clean_buffer(*buffer);??
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	char *buffer;
	
	start();
	init_loop(&buffer);
}