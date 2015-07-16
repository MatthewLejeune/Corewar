/*
** check_name.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Apr  8 15:02:45 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:24:04 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void		check_name(char **tab)
{
  int		cur_case;
  int		found;

  cur_case = -1;
  found = 0;
  while (tab[++cur_case] != NULL && found == 0)
    if (my_strncmp(tab[cur_case], NAME_CMD_STRING,
		   my_strlen(NAME_CMD_STRING)) == 0)
      found = 1;
  if (found == 0)
    my_exit("Name field not found.", found - 1);
  if (my_strlen(get_name(tab[cur_case - 1])) > PROG_NAME_LENGTH)
    my_exit("Name too long.", cur_case);
  if (get_nindex_of(tab[cur_case - 1], '"', 1) == -1 ||
      get_nindex_of(tab[cur_case - 1], '"', 2) == -1)
    my_exit("Missing '\"' char.", cur_case);
}

void		check_comment(char **tab)
{
  int		cur_case;
  int		found;

  cur_case = -1;
  found = 0;
  while (tab[++cur_case] != NULL && found == 0)
    if (my_strncmp(tab[cur_case], COMMENT_CMD_STRING,
		   my_strlen(COMMENT_CMD_STRING)) == 0)
      found = 1;
  if (found == 0)
    my_exit("Comment field not found.", found);
  if (my_strlen(get_name(tab[cur_case - 1])) > COMMENT_LENGTH)
    my_exit("Comment too long.", cur_case);
  else if (get_nindex_of(tab[cur_case - 1], '"', 1) == -1 ||
	   get_nindex_of(tab[cur_case - 1], '"', 2) == -1)
    my_exit("Missing '\"' char.", cur_case);
}
