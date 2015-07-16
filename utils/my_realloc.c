/*
** my_realloc.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 19:47:18 2015 Matthew LEJEUNE
** Last update Sat Apr 11 16:57:24 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char		*my_realloc(char *str, int size)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + size + 1))) == NULL)
    return (NULL);
  if (str)
    {
      while (str[++cur_char])
	new_str[cur_char] = str[cur_char];
      free(str);
    }
  new_str[cur_char] = '\0';
  return (new_str);
}

char		**my_realloc_double(char **tab, int size)
{
  int		cur_case;
  char		**new_tab;

  cur_case = -1;
  if ((new_tab = malloc(sizeof(char *) * (get_nb_elem_tab(tab) + size + 1))) == NULL)
    return (NULL);
  if (tab)
    {
      while (tab[++cur_case])
	new_tab[cur_case] = tab[cur_case];
    }
  return (new_tab);
}
