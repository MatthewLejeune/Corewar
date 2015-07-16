/*
** my_exit.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Mar 19 17:53:19 2015 Matthew LEJEUNE
** Last update Sun Apr 12 17:58:11 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void		my_exit(char *msg, int line)
{
  my_printf("ERROR : Line %d :: %s\n", line + 1, msg);
  exit(EXIT_FAILURE);
}
