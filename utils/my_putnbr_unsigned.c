/*
** my_putnbr_unsigned.c for putnbrunsigned in /home/boiven_d/PSU_2014_my_printf/src
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Fri Nov 14 14:20:43 2014 David Boivent
** Last update Sun Apr 12 17:42:44 2015 Matthew LEJEUNE
*/

#include "corewar.h"

unsigned int     last_while_unsigned(unsigned int nb)
{
  unsigned int  max_int;
  unsigned int  nb_display;

  nb_display = 0;
  max_int = 1000000000;
  while ((nb / max_int) == 0)
    max_int = max_int / 10;
  while (max_int != 0)
    {
      nb_display = nb / max_int;
      my_putchar(nb_display + 48);
      nb = nb % max_int;
      max_int = (max_int / 10);
    }
    return (0);
}

unsigned int     my_putnbr_unsigned(unsigned int nb)
{
  if ( nb == 0 )
    my_putchar(48);
  else
    last_while_unsigned(nb);
  return (0);
}
