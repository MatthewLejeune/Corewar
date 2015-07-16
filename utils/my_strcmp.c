/*
** my_strcmp.c for my_strcmp in /home/roy_n/rendu/minishell1/lib/my
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Mon Jan 19 14:51:24 2015 Nathan Roy
** Last update Sun Apr 12 16:20:26 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0)
    {
      if (s2[i] == 0)
	return (1);
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (s2[i] == 0)
    return (0);
  return (1);
}
