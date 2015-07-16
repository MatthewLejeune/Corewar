/*
** my_put_nbr.c for putnbr in /home/boiven_d/PSU_2014_my_printf
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Fri Nov 14 14:01:25 2014 David Boivent
** Last update Sun Apr 12 17:42:05 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int     last_while(int nb, int nb_display, int max_int)
{
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

int     my_put_nbr(int nb)
{
  int   max_int;
  int   nb_display;

  nb_display = 0;
  max_int = 1000000000;
  if ( nb != -2147483648 && nb < 0 )
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if ( nb == 0 )
    {
      my_putchar(48);
      return (0);
    }
  if ( nb == -2147483648 )
    my_putstr("-2147483648");
  else
    last_while(nb, nb_display, max_int);
  return (0);
}
