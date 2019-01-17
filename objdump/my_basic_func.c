/*
** EPITECH PROJECT, 2018
** my_basic_func.c
** File description:
** basic func objdump
*/

#include "objdump.h"

void	my_putcarac(int nb, char c)
{
	int	i = 0;

	while (i < nb)
	{
		printf("%c", c);
		i++;
	}
}

static void	print_hexa(char *str, int end)
{
	int	i = 0;

	my_putcarac(2, ' ');
	while (i < 16)
	{
		if (i < end)
		{
			if (str[i] >= ' ' && str[i] <= '~')
				my_putcarac(1, str[i]);
			else
				my_putcarac(1, '.');
		}
		else
			my_putcarac(1, ' ');
		i++;
	}
	printf("\n");
}

void	print_sub(char *str, int nb, int i)
{
	int	space;

	space = 16 - nb;
	space = space + (space / 4) + (16 - nb);
	my_putcarac(space, ' ');
	if (i != 0)
		print_hexa(str, nb);
}

void	print_sub_hexa(char *str, unsigned int *hex, int i)
{
	if (i != 0)
		print_hexa(str, 16);
	printf(" %04x ", *hex);
	*hex += 0x10;
}
