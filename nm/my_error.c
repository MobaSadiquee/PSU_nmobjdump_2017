/*
** EPITECH PROJECT, 2018
** error
** File description:
** error func for nm
*/

#include "nm.h"

void    do_exit(char *str, int value)
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

int     do_return(char *str, int value)
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
