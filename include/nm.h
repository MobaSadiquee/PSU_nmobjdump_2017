/*
** EPITECH PROJECT, 2018
** nm
** File description:
** header for nm
*/

#ifndef _NM_H_
# define _NM_H_

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <elf.h>
#include <string.h>
#include <stdbool.h>

#include "nm_list.h"

typedef struct  s_data
{
	int		fd;
	t_data32	data32;
	t_data64	data64;
}               t_data;

char	get_type(int, int, int, int);
bool	sort_alpha(char *, char *);

int	do_return(char *, int);
void	do_exit(char *, int);

void		add_64(t_data64 *);
void		print_64(t_data64 *, Elf64_Sym *, int);
t_elem64	*help_64(t_elem64 *, int);
t_elem64	*sort_64(t_elem64 *, t_elem64 *, int, int);
int		check_64(t_data *);
void		nm_64(t_data64 *);

void		add_32(t_data32 *);
void		print_32(t_data32 *, Elf32_Sym *, int);
t_elem32	*help_32(t_elem32 *, int);
t_elem32	*sort_32(t_elem32 *, t_elem32 *, int, int);
int		check_32(t_data *);
void		nm_32(t_data32 *);

#endif  /* !_NM_H_ */
