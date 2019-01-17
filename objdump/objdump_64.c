/*
** EPITECH PROJECT, 2018
** objdump_64.c
** File description:
** objdump64 main function
*/

#include "objdump.h"

static	int	good_64(t_data64 *data, int i)
{
	int	mem;
	int	write;

	write = data->shdr[i].sh_flags & SHF_WRITE;
	mem = data->shdr[i].sh_flags & SHF_ALLOC;
	if (data->shdr[i].sh_type == SHT_NOBITS)
		return (1);
	if (data->shdr[i].sh_type == SHT_PROGBITS
		|| data->shdr[i].sh_type == SHT_NOTE
		|| mem == SHF_ALLOC || write == SHF_WRITE)
		return (1);
	return (0);
}

void	objdump_64(t_data64 *data)
{
	int     i = 0;

	print_head_64(data);
	printf("\n");
	while (i < data->elf->e_shnum)
	{
		if (good_64(data, i) && data->shdr[i].sh_size != 0)
			print_64(data, i);
		i++;
	}
}

int	check_64(t_data *data)
{
	if (data->data64.elf->e_ident[EI_MAG0] != ELFMAG0
		|| data->data64.elf->e_ident[EI_MAG1] != ELFMAG1
		|| data->data64.elf->e_ident[EI_MAG2] != ELFMAG2
		|| data->data64.elf->e_ident[EI_MAG3] != ELFMAG3
		|| data->data64.elf->e_ident[EI_CLASS] != ELFCLASS64)
		return (do_return("objdump: File format not recognized\n", 84));
	data->data64.shdr = (data->data64.data + data->data64.elf->e_shoff);
	if (data->data64.shdr == NULL)
		return (do_return("objdump: Invalid pointer\n", 84));
	data->data64.strtab = (data->data64.data + data->data64.shdr
			[data->data64.elf->e_shstrndx].sh_offset);
	if (data->data64.strtab == NULL)
		return (do_return("objdump: Invalid pointer\n", 84));
	return (0);
}
