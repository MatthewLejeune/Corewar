/*
** my_getnbr.c for my_getnbr in /home/roy_n/rendu/Piscine_C_J07
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Tue Oct  7 11:21:44 2014 Nathan Roy
** Last update Sun Apr 12 16:19:34 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	negat(char *nbr, int nb_retur)
{
  int	i;

  i = 0;
  while (nbr[i] == '-' || nbr[i] == '+')
    {
      if (nbr[i + 1] != '-' && nbr[i + 1] != '+')
	{
	  if (nbr[i] == '-')
	    {
	      nb_retur = nb_retur * (-1);
	      return (nb_retur);
	    }
	}
      i++;
    }
  return (nb_retur);
}

int	limite(char *nbr)
{
  int	j;

  j = 0;
  while (nbr[j] == '-' || nbr[j] == '+')
    j++;
  if (nbr[j] >= 48 && nbr[j] <= 57 && nbr[j] != 0)
    {
      while (nbr[j] >= 48 && nbr[j] <= 57 && nbr[j] != 0)
	{
	  j++;
	}
      j--;
    }
  return (j);
}

int	my_getnbr(char *nbr)
{
  char	*base = "0123456789";
  int	i;
  int	nb_retur;
  int	j;
  int	inv;

  inv = 1;
  nb_retur = 0;
  i = 0;
  j = limite(nbr);
  while (base[i] != 0)
    {
      if (base[i] == nbr[j] && base[i] != 0)
	{
	  i = i * inv;
	  nb_retur = nb_retur + i;
	  inv = inv * 10;
	  i = (-1);
	  j--;
	}
      i++;
    }
  nb_retur = negat(nbr, nb_retur);
  return (nb_retur);
}
