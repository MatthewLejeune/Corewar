/*
** putn_base.c for nbrbase in /home/boiven_d/PSU_2014_my_printf
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Fri Nov 14 13:59:11 2014 David Boivent
** Last update Sun Apr 12 17:41:09 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	count_base(char *base)
{
  int	i;

  i = 0;
  while (base[i] != 0)
      i++;
  return (i);
}

int	putn_base2(int nb, char *base)
{
  int	n;

  n = count_base(base);
  if (nb / n >= 0)
    {
      if (nb /n == 0)
        nb = nb;
      else
	putn_base2(nb / n, base);
    }
  my_putchar(base[nb % n]);
  return (0);
}

int	putn_base(int nb, char *base)
{
  if (nb > 0)
    putn_base2(nb, base);
  else if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  else
    {
      nb = nb * -1;
      if (count_base(base) > 2 && nb != 0)
        my_putchar('-');
      putn_base2(nb, base);
    }
    return (0);
}
