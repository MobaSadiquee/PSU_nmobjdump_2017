/*
** EPITECH PROJECT, 2018
** func_64bits
** File description:
** func for 64bits nm
*/

#include "nm.h"
#include "nm_list.h"

t_elem64	*help_64(t_elem64 *base, int size)
{
	int		pos = 0;
	t_elem64	*new;

	new = malloc(sizeof(t_elem64) * size);
	if (new == NULL)
		return (NULL);
	for (int i = 0; i < size; ++i)
	{
		new[i].elem = NULL;
		new[i].name = NULL;
		new[i].pos = 0;
	}
	while ((pos + 1) < size)
	{
		new = sort_64(base, new, size, pos);
		pos++;
	}
	return (new);
}

t_elem64	*sort_64(t_elem64 *base, t_elem64 *elem, int size, int pos)
{
	int		i = 0;
	t_elem64	*tmp = &base[0];

	while (i < size) {
		if (base[i].elem && *(base[i].name) && base[i].elem != NULL)
			if ((sort_alpha(tmp->name, base[i].name)) == true)
				tmp = &base[i];
		i++;
	}
	if (tmp->elem && *tmp->name && tmp->elem->st_info != STT_FILE) {
		elem[pos].name = tmp->name;
		elem[pos].elem = tmp->elem;
		elem[pos].pos = pos;
	}
	else if (*tmp->name == 0)
		return (elem);
	else
		elem[pos].elem = NULL;
	tmp->elem = NULL;
	return (elem);
}

void	print_64(t_data64 *data, Elf64_Sym *sym, int i)
{
	if (sym->st_value)
	{
		printf("%016lx %c %s\n", sym->st_value,
			get_type(data->shdr[sym->st_shndx].sh_type,
				data->shdr[sym->st_shndx].sh_flags,
				sym->st_info,
				sym->st_value),
			data->elem[i].name);
	}
	else
	{
		printf("                 %c %s\n",
			get_type(data->shdr[sym->st_shndx].sh_type,
				data->shdr[sym->st_shndx].sh_flags,
				sym->st_info,
				sym->st_value),
			data->elem[i].name);
	}
}

int	check_64(t_data *data)
{
	if (data->data64.elf->e_ident[EI_MAG0] != ELFMAG0
		|| data->data64.elf->e_ident[EI_MAG1] != ELFMAG1
		|| data->data64.elf->e_ident[EI_MAG2] != ELFMAG2
		|| data->data64.elf->e_ident[EI_MAG3] != ELFMAG3
		|| data->data64.elf->e_ident[EI_CLASS] != ELFCLASS64)
		return (do_return("nm: File format not recognized\n", 84));
	data->data64.shdr = (data->data64.data + data->data64.elf->e_shoff);
	if (data->data64.shdr == NULL)
		return (do_return("nm: Invalid pointer\n", 84));
	return (0);
}
