/*
** my_char_is_alpha.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Mar 19 16:05:46 2015 Matthew LEJEUNE
** Last update Thu Mar 19 16:26:09 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		my_char_is_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (0);
  else if (c >= 'A' && c <= 'Z')
    return (0);
  return (-1);
}
