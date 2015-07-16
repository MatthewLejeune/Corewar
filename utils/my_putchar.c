/*
** my_putchar.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr  6 19:07:17 2015 Matthew LEJEUNE
** Last update Mon Apr  6 19:08:47 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
