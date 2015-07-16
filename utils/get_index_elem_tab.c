/*
** get_index_elem_tab.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 21:41:28 2015 Matthew LEJEUNE
** Last update Thu Mar 19 17:58:07 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		get_index_elem_tab(char **tab, char *elem)
{
  int		cur_pos;
  int		found;

  cur_pos = -1;
  found = -1;
  while (tab[++cur_pos])
    if (my_strncmp(tab[cur_pos], elem, my_strlen(elem)) == 0)
      found = cur_pos;
  return (found);
}
