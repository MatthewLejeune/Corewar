/*
** my_putnbr_long.c for putnbrlong in /home/boiven_d/PSU_2014_my_printf
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Fri Nov 14 14:05:25 2014 David Boivent
** Last update Sun Apr 12 17:42:28 2015 Matthew LEJEUNE
*/

#include "corewar.h"

long	last_while_long(long nb, long nb_display, long max_int)
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

long	my_putnbr_long(long nb)
{
  long	max_int;
  long	nb_display;
  long	check;

  nb_display = 0;
  check = -9223372036854775808U;
  max_int = 1000000000000000000;
  if ( nb != check && nb < 0 )
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if ( nb == 0 )
    my_putchar(48);
  if ( nb == check)
    my_putstr("-9223372036854775808");
  else
    last_while_long(nb, nb_display, max_int);
  return (0);
}
