/*
** EPITECH PROJECT, 2018
** list_32.h
** File description:
** header for 32bits nm
*/

#ifndef NM_LIST_H_
# define NM_LIST_H_

typedef struct          s_elem32
{
	Elf32_Sym	*elem;
	char		*name;
	int		pos;
}			t_elem32;

typedef struct		s_data32
{
	Elf32_Sym	*sym;
	Elf32_Ehdr	*elf;
	Elf32_Shdr	*shdr;
	char		*str;
	int		size;
	void		*data;
	t_elem32	*elem;
}			t_data32;

typedef struct		s_elem64
{
	Elf64_Sym	*elem;
	char		*name;
	int		pos;
}			t_elem64;

typedef struct		s_data64
{
	Elf64_Sym	*sym;
	Elf64_Ehdr	*elf;
	Elf64_Shdr	*shdr;
	char		*str;
	int		size;
	void		*data;
	t_elem64	*elem;
}			t_data64;

#endif  /* !NM_LIST_H_ */
