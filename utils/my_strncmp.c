/*
** my_strncmp.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 19:11:36 2015 Matthew LEJEUNE
** Last update Sat Apr 11 12:12:47 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		my_strncmp(char *src, char *cmp, int length)
{
  int		cur_char;

  cur_char = -1;
  while (++cur_char < length && src[cur_char] && cmp[cur_char])
    if (src[cur_char] != cmp[cur_char])
      return (-1);
  if (cur_char < length)
    return (-1);
  return (0);
}
