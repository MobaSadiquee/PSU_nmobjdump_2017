/*
** EPITECH PROJECT, 2018
** objdump_32.c
** File description:
** main func for objdump32
*/

#include "objdump.h"

static  int     good_32(t_data32 *data, int i)
{
	int     mem;
	int     write;

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

void    objdump_32(t_data32 *data)
{
	int     i = 0;

	print_head_32(data);
	while (i < data->elf->e_shnum)
	{
		if (good_32(data, i) && data->shdr[i].sh_size != 0)
			print_32(data, i);
		i++;
	}
}

int     check_32(t_data *data)
{
	if (data->data32.elf->e_ident[EI_MAG0] != ELFMAG0
		|| data->data32.elf->e_ident[EI_MAG1] != ELFMAG1
		|| data->data32.elf->e_ident[EI_MAG2] != ELFMAG2
		|| data->data32.elf->e_ident[EI_MAG3] != ELFMAG3
		|| data->data32.elf->e_ident[EI_CLASS] != ELFCLASS32)
		return (do_return("objdump: File format not recognized\n", 84));
	data->data32.shdr = (data->data32.data + data->data32.elf->e_shoff);
	if (data->data32.shdr == NULL)
		return (do_return("objdump: Invalid pointer\n", 84));
	data->data32.strtab = (data->data32.data + data->data32.shdr
			[data->data32.elf->e_shstrndx].sh_offset);
	if (data->data32.strtab == NULL)
		return (do_return("objdump: Invalid pointer\n", 84));
	return (0);
}
