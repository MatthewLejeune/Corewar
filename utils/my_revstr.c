/*
** my_revstr.c for my_revstr in /home/roy_n/rendu/Piscine_C_J06
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Mon Oct  6 11:09:48 2014 Nathan Roy
** Last update Sun Apr 12 16:20:09 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char	*my_revstr(char *str)
{
  int	inv;
  int	i;
  char	sauv;

  i = 0;
  inv = 0;
  while (str[inv] != 0)
    {
      inv++;
    }
  inv--;
  while (inv > i)
    {
      sauv = str[i];
      str[i] = str[inv];
      str[inv] = sauv;
      i++;
      inv--;
    }
  return (str);
}
