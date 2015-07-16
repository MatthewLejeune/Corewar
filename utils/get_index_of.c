/*
** get_index_of.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 21:49:56 2015 Matthew LEJEUNE
** Last update Thu Mar 19 18:20:26 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		get_index_of(char *str, char c)
{
  int		cur_char;

  cur_char = -1;
  while (str[++cur_char])
    if (str[cur_char] == c)
      return (cur_char);
  return (-1);
}

int		get_nindex_of(char *str, char c, int nb)
{
  int		cur_char;
  int		count;

  cur_char = -1;
  count = 0;
  while (str[++cur_char])
    if (str[cur_char] == c)
      if (++count == nb)
	return (cur_char);
  return (-1);
}
