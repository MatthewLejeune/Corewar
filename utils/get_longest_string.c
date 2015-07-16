/*
** get_longest_string.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 12 18:47:05 2015 Matthew LEJEUNE
** Last update Sun Apr 12 18:47:42 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	get_longest_string(char *src, char *str)
{
  int		cur_char;
  int		cur_char_str;

  cur_char = 0;
  cur_char_str = 0;
  if (src && str)
    {
      while (src[cur_char])
	cur_char++;
      while (str[cur_char_str])
	cur_char_str++;
    }
  return ((cur_char >= cur_char_str) ? cur_char : cur_char_str);
}
