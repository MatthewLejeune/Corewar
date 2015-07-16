/*
** my_power_rec.c for my_power_rec in /home/roy_n/rendu/Piscine_C_J05
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Fri Oct  3 15:39:55 2014 Nathan Roy
** Last update Sun Apr 12 16:19:46 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	my_power(int nb, int power, int i, int var_nb)
{
  if (i < (power - 1))
    {
      if (nb > 0)
        {
          nb = nb * var_nb;
        }
      else
        {
          nb = 0;
	}
      i++;
      nb = my_power(nb, power, i, var_nb);
    }
  else
    {
      return (nb);
    }
  return (nb);
}

int	my_power_rec(int nb, int power)
{
  int   i;
  int   var_nb;

  if (power == 0)
    {
      nb = 1;
    }
  else if (power < 0)
    {
      nb = 0;
    }
  else
    {
      i = 0;
      var_nb = nb;
      nb = my_power(nb, power, i, var_nb);
    }
  return (nb);
}
