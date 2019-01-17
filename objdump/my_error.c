/*
** EPITECH PROJECT, 2018
** my_error.c
** File description:
** error func
*/

#include "objdump.h"

void	do_exit(char *str, int value)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(value);
}

int	do_return(char *str, int value)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (value);
}
