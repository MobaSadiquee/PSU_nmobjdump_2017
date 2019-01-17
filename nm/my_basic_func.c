/*
** EPITECH PROJECT, 2018
** func_utils
** File description:
** moult func for nm
*/

#include "nm.h"

char	get_type(int type, int flags, int info, int value)
{
	char	res;

	res = 'U';
	if (type == SHT_NOBITS && flags == (SHF_WRITE + SHF_ALLOC))
		res = 'B';
	if ( (type == SHT_PROGBITS || type == SHT_DYNAMIC)
		&& flags == (SHF_WRITE + SHF_ALLOC))
		res = 'D';
	if (type == SHT_PROGBITS && flags == (SHF_ALLOC + SHF_EXECINSTR))
		res = 'T';
	if (type == SHT_PROGBITS && flags == SHF_ALLOC)
		res = 'R';
	if (ELF64_ST_BIND(info) == STB_WEAK)
		res = 'W';
	if (type > SHT_DYNSYM)
		res = 'T';
	if ((ELF64_ST_BIND(info) == STB_LOCAL || value == 0) && res != 'U')
		res += 32;
	return (res);
}

static char	*minus_alpha(char *str)
{
	char	*new_str;
	int	i = 0;

	if (str == NULL)
		return (NULL);
	new_str = strdup(str);
	while (new_str[i] != '\0')
	{
		if (new_str[i] >= 65 && new_str[i] <= 90)
			new_str[i] = new_str[i] + 32;
		i++;
	}
	return (new_str);
}

static bool	sort_help(char *str1, char *str2, int i, int j)
{
	char	*newstr1;
	char	*newstr2;

	newstr1 = minus_alpha(str1);
	newstr2 = minus_alpha(str2);
	while (newstr1[i] != '\0' || newstr2[j] != '\0') {
		if (newstr1[i] < newstr2[j]) {
			free(newstr1);
			free(newstr2);
			return (false);
		}
		if (newstr1[i] > newstr2[j]) {
			free(newstr1);
			free(newstr2);
			return (true);
		}
		i++;
		j++;
	}
	return (false);
}

bool	sort_alpha(char *str1, char *str2)
{
	int	i = 0;
	int	j = 0;

	if (str1 == NULL)
		return (true);
	if (*str1 <= 32)
		return (true);
	if (str1[i] == '_' || str2[j] == '_')
	{
		while (str1[i] == '_')
			i++;
		while (str2[j] == '_')
			j++;
	}
	if ((sort_help(str1, str2, i, j)) == true)
		return (true);
	return (false);
}
