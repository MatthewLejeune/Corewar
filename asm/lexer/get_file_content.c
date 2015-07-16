/*
** get_file_content.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 22:01:04 2015 Matthew LEJEUNE
** Last update Sun Apr 12 16:48:48 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char		**get_file_content(int fd)
{
  int		cur_case;
  int		cur_char;
  char		*str;
  char		**tab;

  cur_case = 0;
  tab = NULL;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] != COMMENT_CHAR)
	{
	  cur_char = -1;
	  if ((tab = my_realloc_double(tab, 1)) == NULL)
	    return (NULL);
	  while (str[++cur_char] && str[cur_char] != COMMENT_CHAR);
	  str[cur_char] = 0;
	  tab[cur_case] = str;
	  cur_case++;
	} else
	free(str);
    }
  tab[cur_case] = NULL;
  return (tab);
}
