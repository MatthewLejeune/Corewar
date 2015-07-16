/*
** check_label.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Apr  9 09:52:01 2015 Matthew LEJEUNE
** Last update Thu Apr  9 11:02:42 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void		check_label(char **tab)
{
  int		cur_char;
  int		cur_char_bis;
  int		cur_case;
  int		found;
  char		*label;

  cur_case = -1;
  while (tab[++cur_case])
    {
      if (is_label(tab[cur_case]) != -1)
	{
	  cur_char = -1;
	  label = get_label(tab[cur_case]);
	  while (label[++cur_char])
	    {
	      found = 0;
	      cur_char_bis = -1;
	      while (LABEL_CHARS[++cur_char_bis])
		if (label[cur_char] == LABEL_CHARS[cur_char_bis])
		  found = 1;
	      if (found == 0)
		my_exit("Unrecognized label char.", cur_case);
	    }
	}
    }
}
