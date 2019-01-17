/*
** EPITECH PROJECT, 2018
** 64bits
** File description:
** 64bits for nm
*/

#include "nm.h"
#include "nm_list.h"

void	init_64(t_data64 *data)
{
	data->sym = NULL;
	data->str = NULL;
	data->size = 0;
}

void	sym_64(t_data64 *data)
{
	int	i = 0;

	init_64(data);
	while (i < data->elf->e_shnum)
	{
		if (data->shdr[i].sh_type == SHT_STRTAB
			&& (data->shdr[i].sh_flags | SHF_ALLOC) == SHF_ALLOC)
			data->str = (data->data + data->shdr[i].sh_offset);
		if (data->shdr[i].sh_type == SHT_SYMTAB)
		{
			data->size = data->shdr[i].sh_size / sizeof(Elf64_Sym);
			data->sym = (data->data + data->shdr[i].sh_offset);
		}
		i++;
	}
	if (data->sym == NULL || data->str == NULL || data->size == 0)
		do_exit("nm: No symbole in the file\n", 84);
}

void	add_64(t_data64 *data)
{
	t_elem64	*elem;
	int		i = 0;

	elem = malloc(data->size * sizeof(t_elem64));
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

void    nm_64(t_data64 *data)
{
	int		i = 0;
	Elf64_Sym	*tmp;
	t_elem64	*new;

	sym_64(data);
	add_64(data);
	new = help_64(data->elem, data->size);
	if (new == NULL)
		return (do_exit("nm: Malloc failed", 84));
	data->elem = new;
	while (i < data->size)
	{
		tmp = data->elem[i].elem;
		if (tmp != NULL)
			print_64(data, tmp, i);
		i++;
	}
	if (data->elem)
		free(data->elem);
}
