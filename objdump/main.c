/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for the objdump function
*/

#include "objdump.h"

int	open_file(t_data *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
	{
		if ((strcmp(file, "a.out")) == 0)
			printf("objdump: a.out: No such file\n");
		else
			printf("objdump: %s: No such file\n", file);
		return (84);
	}
	data->data64.data = mmap(NULL, lseek(data->fd, 0, SEEK_END),
			PROT_READ, MAP_SHARED, data->fd, 0);
	if (data->data64.data == MAP_FAILED)
		return (do_return("objdump: mmap failed\n", 84));
	data->data64.elf = (Elf64_Ehdr*)data->data64.data;
	if (data->data64.elf == NULL)
		return (do_return("objdump: Invalid pointer\n", 84));
	return (0);
}

int	my_objdump(t_data *data, char *file)
{
	if (open_file(data, file) == 84)
		return (84);
	if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS32) {
		if ((check_32(data)) == 84)
			return (84);
		printf("\n%s:     file format elf32-i386\n", file);
		objdump_32(&(data->data32));
	}
	else if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS64) {
		if ((check_64(data)) == 84)
			return (84);
		printf("\n%s:     file format elf64-x86-64\n", file);
		objdump_64(&(data->data64));
	}
	else
		return (do_return("objdump: File format not recognized\n", 84));
	if (data->fd != -1)
		close(data->fd);
	return (0);
}

int	main(int ac, char **av)
{
	int	i = 1;
	t_data	data;
	int	value = 0;

	if (ac == 1)
		if (my_objdump(&data, "a.out") == 84)
			return (84);
	while (i < ac)
	{
		if (my_objdump(&data, av[i]) == 84)
			value = 84;
		i++;
	}
	return (value);
}
