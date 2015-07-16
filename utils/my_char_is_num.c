/*
** my_char_is_num.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Mar 19 16:07:35 2015 Matthew LEJEUNE
** Last update Thu Mar 19 16:26:22 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  return (-1);
}
