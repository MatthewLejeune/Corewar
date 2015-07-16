/*
** my_getnbr_base.c for my_getnbr_base in /home/roy_n/rendu/printf
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Mon Nov 10 11:15:27 2014 Nathan Roy
** Last update Wed Apr  8 16:59:03 2015 Nathan Roy
*/

#include "corewar.h"
#include "op.h"

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	j;
  int	result;

  j = 0;
  result = 0;
  i = 0;
  my_revstr(str);
  while (str[j] != 0)
    {
      i = 0;
      while (str[j] != base[i])
	i++;
      result = result + (i * my_power_rec(my_strlen(base), j));
      j++;
    }
  return (result);
}
