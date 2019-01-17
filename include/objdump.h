/*
** EPITECH PROJECT, 2018
** objdump.h
** File description:
** header for the objdump
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <elf.h>
#include <string.h>
#include <ctype.h>

typedef struct		s_data64
{
	Elf64_Ehdr	*elf;
	Elf64_Shdr	*shdr;
	void		*data;
	char		*strtab;
	char		*file;
}			t_data64;

typedef struct          s_data32
{
	Elf32_Ehdr      *elf;
	Elf32_Shdr      *shdr;
	void            *data;
	char            *strtab;
	char            *file;
}                       t_data32;

typedef struct		s_data
{
	int		fd;
	t_data32	data32;
	t_data64	data64;
}			t_data;

void	objdump_64(t_data64 *);
int	check_64(t_data *);
void	print_64(t_data64 *, int);
void	print_head_64(t_data64 *);

void	objdump_32(t_data32 *);
int	check_32(t_data *);
void	print_32(t_data32 *, int);
void	print_head_32(t_data32 *);

void	my_putchar(char);
void	my_putcarac(int, char);
void	print_sub(char *, int, int);
void	print_sub_hexa(char *, unsigned int *, int);
int	do_return(char *, int);
void	do_exit(char *, int);

#endif  /* !OBJDUMP_H_ */
