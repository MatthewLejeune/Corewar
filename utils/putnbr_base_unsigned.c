/*
** putnbr_base_unsigned.c for putnbase_unsigned in /home/boiven_d/synaptique-boiven_d/printf
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Sat Feb  7 17:52:40 2015 David Boivent
** Last update Sun Apr 12 17:44:17 2015 Matthew LEJEUNE
*/

#include "corewar.h"

unsigned int	count_base_unsi(char *base)
{
  int   i;

  i = 0;
  while (base[i] != 0)
    i++;
  return (i);
}

unsigned int     putn_base2_unsi(unsigned int nb, char *base)
{
  int   n;

  n = count_base_unsi(base);
  if (nb == 0)
    nb = nb;
  else
    putn_base2_unsi(nb / n, base);
  my_putchar(base[nb % n]);
  return (0);
}

unsigned int     putn_base_unsi(unsigned int nb, char *base)
{
  if (nb > 0)
    putn_base2_unsi(nb, base);
  else if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  else
    {
      nb = nb * -1;
      if (count_base_unsi(base) > 2 && nb != 0)
        my_putchar('-');
      putn_base2_unsi(nb, base);
    }
  return (0);
}
