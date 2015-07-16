/*
** my_putstr.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr  6 19:07:48 2015 Matthew LEJEUNE
** Last update Sat Apr 11 12:39:59 2015 Nathan Roy
*/

#include "corewar.h"

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
