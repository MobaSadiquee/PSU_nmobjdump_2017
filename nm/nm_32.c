/*
** EPITECH PROJECT, 2018
** nm_32.c
** File description:
** 32bits for nm
*/

#include "nm.h"
#include "nm_list.h"

void	init_32(t_data32 *data)
{
	data->sym = NULL;
	data->str = NULL;
	data->size = 0;
}

void	sym_32(t_data32 *data)
{
	int	i = 0;

	init_32(data);
	while (i < data->elf->e_shnum)
	{
		if (data->shdr[i].sh_type == SHT_STRTAB
		&& (data->shdr[i].sh_flags | SHF_ALLOC) == SHF_ALLOC)
			data->str = (data->data + data->shdr[i].sh_offset);
		if (data->shdr[i].sh_type == SHT_SYMTAB)
		{
			data->size = data->shdr[i].sh_size / sizeof(Elf32_Sym);
			data->sym = (data->data + data->shdr[i].sh_offset);
		}
		i++;
	}
	if (data->sym == NULL || data->str == NULL || data->size == 0)
		do_exit("nm: No symbole in the file\n", 84);
}

void	add_32(t_data32 *data)
{
	t_elem32	*elem;
	int		i = 0;

	elem = malloc(data->size * sizeof(t_elem32));
	if (elem == NULL)
		do_exit("nm: Malloc failed\n", 84);
	while (i < data->size)
	{
		elem[i].name = (data->str + data->sym[i].st_name);
		elem[i].elem = data->sym + i;
		elem[i].pos = i;
		i++;
	}
	data->elem = elem;
}

void	nm_32(t_data32 *data)
{
	int		i = 0;
	Elf32_Sym	*tmp;
	t_elem32	*new;

	sym_32(data);
	add_32(data);
	new = help_32(data->elem, data->size);
	if (new == NULL)
		return (do_exit("nm: Malloc failed", 84));
	data->elem = new;
	while (i < data->size)
	{
		tmp = data->elem[i].elem;
		if (tmp != NULL)
			print_32(data, tmp, i);
		i++;
	}
	if (data->elem)
		free(data->elem);
}
