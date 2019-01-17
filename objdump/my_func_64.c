/*
** EPITECH PROJECT, 2018
** my_func_64.c
** File description:
** func for objdump64
*/

#include "objdump.h"
#include "flags.h"

static void	help_64(char *str, int i)
{
	if (i % 16 != 0)
		print_sub(str, i % 16, i);
	if (i % 16 == 0)
		print_sub(str, 16, i);
}

void	loop_print(t_data64 *data, char *str, unsigned int hex, int nb)
{
	unsigned int	i = 0;
	unsigned char	tmp;

	while (i < data->shdr[nb].sh_size)
	{
		tmp = *(char*)(data->data + data->shdr[nb].sh_offset + i);
		if (i % 16 == 0)
			print_sub_hexa(str, &hex, i);
		else if (i % 4 == 0)
			my_putcarac(1, ' ');
		printf("%02x", tmp);
		str[i % 16] = tmp;
		i++;
	}
	help_64(str, i);
}

void	print_64(t_data64 *data, int shnum)
{
	char		*str;
	unsigned int	hex = 0;

	str = malloc(sizeof(char) * 16);
	if (str == NULL)
		do_exit("objdump : malloc failed\n", 84);
	hex = data->shdr[shnum].sh_addr;
	printf("Contents of section %s :\n",
		&(data->strtab[data->shdr[shnum].sh_name]));
	loop_print(data, str, hex, shnum);
	free(str);
}

void	print_head_64(t_data64 *data)
{
	int	ftypes[ET_NUM];
	char	*types[ET_NUM];

	types[ET_NONE] = "";
	ftypes[ET_NONE] = 0x0;
	types[ET_REL] = "HAS_RELOC, HAS_SYMS";
	ftypes[ET_REL] = 0x11;
	types[ET_EXEC] = "EXEC_P, HAS_SYMS, D_PAGED";
	ftypes[ET_EXEC] = 0x112;
	types[ET_DYN] = "HAS_SYMS, DYNAMIC, D_PAGED";
	ftypes[ET_DYN] = 0x150;
	types[ET_CORE] = "";
	ftypes[ET_CORE] = 0x0;
	if (data->elf->e_type < ET_NUM)
	{
		printf("architecture: i386:x86-64, flags 0x%08x:\n",
			ftypes[data->elf->e_type]);
		printf("%s\n", types[data->elf->e_type]);
		printf("start address 0x%016lx\n", data->elf->e_entry);
	}
}

