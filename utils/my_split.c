/*
** my_split.c for sample in /home/lejeun_m/sample/split
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Fri Mar 20 22:40:03 2015 Matthew LEJEUNE
** Last update Sat Mar 21 10:19:08 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		get_nb_elem_split(char *str, char c)
{
  int		cur_char;
  int		nb;

  cur_char = -1;
  nb = 0;
  while (str[++cur_char])
    if (str[cur_char] == c)
      nb++;
  return (nb + 1);
}

char		*char_concat(char *str, char c)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[++cur_char])
    new_str[cur_char] = str[cur_char];
  new_str[cur_char] = c;
  new_str[++cur_char] = '\0';
  free(str);
  return (new_str);
}

char		**my_split(char *str, char sep)
{
  int		cur_case;
  int		cur_char;
  char		**tab;

  cur_char = -1;
  cur_case = 0;
  if ((tab = malloc(sizeof(char *) * (get_nb_elem_split(str, sep) + 2))) == NULL ||
      (tab[0] = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  tab[0][0] = '\0';
  while (str[++cur_char])
      if (str[cur_char] == sep)
	{
	  if ((tab[++cur_case] = malloc(sizeof(char) * 1)) == NULL)
	    return (NULL);
	  tab[cur_case][0] = '\0';
	}
      else
	{
	  if ((tab[cur_case] = my_realloc(tab[cur_case], 1)) == NULL)
	    return (NULL);
	  tab[cur_case] = char_concat(tab[cur_case], str[cur_char]);
	}
  tab[++cur_case] = NULL;
  return (tab);
}
