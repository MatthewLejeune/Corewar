/*
** my_substring.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 21:13:29 2015 Matthew LEJEUNE
** Last update Thu Mar 19 18:27:22 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char		*my_substr(char *str, int start, int end)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * (end - start + 1))) == NULL)
    return (NULL);
  while (++start < end && str[start] != '\0')
    new_str[++cur_char] = str[start];
  new_str[++cur_char] = '\0';
  return (new_str);
}
