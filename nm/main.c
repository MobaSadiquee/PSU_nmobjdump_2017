/*
** EPITECH PROJECT, 2018
** main
** File description:
** main for nm
*/

#include "nm.h"

int	open_file(t_data *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
	{
		if ((strcmp(file, "a.out")) == 0)
			printf("nm: « a.out »: No such file\n");
		else
			printf("nm: « %s »: No such file\n", file);
		return (84);
	}
	data->data64.data = mmap(NULL, lseek(data->fd, 0, SEEK_END),
				PROT_READ, MAP_SHARED, data->fd, 0);
	if (data->data64.data == MAP_FAILED)
		return (do_return("nm: mmap failed\n", 84));
	data->data64.elf = (Elf64_Ehdr*)data->data64.data;
	if (data->data64.elf == NULL)
		return (do_return("nm: Invalid pointer\n", 84));
	return (0);
}

int	my_nm(t_data *data, char *file)
{
	if (open_file(data, file) == 84)
		return (84);
	if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS32)
	{
		if ((check_32(data)) == 84)
			return (84);
		nm_32(&(data->data32));
	}
	else if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS64)
	{
		if ((check_64(data)) == 84)
			return (84);
		nm_64(&(data->data64));
	}
	else
		return (do_return("nm: File format not recognized\n", 84));
	if (data->fd != -1)
		close(data->fd);
	return (0);
}

static void	arg_condition(int i, int ac, char **av)
{
	if ((i + 1) < ac)
		printf("\n %s\n", av[i + 1]);
}

int	main(int ac, char **av)
{
	int		i = 1;
	t_data		data;
	int		final_value;

	final_value = 0;
	if (ac == 1)
		if (my_nm(&data, "a.out") == 84)
			return (84);
	if (ac >= 3)
		printf("\n %s\n", av[i]);
	while (i < ac)
	{
		if (my_nm(&data, av[i]) == 84)
			final_value = 84;
		arg_condition(i, ac, av);
		i++;
	}
	return (final_value);
}
