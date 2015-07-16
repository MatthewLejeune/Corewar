/*
** my_strlen.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 19:20:43 2015 Matthew LEJEUNE
** Last update Mon Mar 23 18:07:36 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		my_strlen(char *str)
{
  int		cur_char;

  cur_char = 0;
  if (str)
    while (str[cur_char])
      cur_char++;
  return (cur_char);
}
