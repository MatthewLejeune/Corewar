/*
** get_basic_champ_info.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar/asm
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 19:02:57 2015 Matthew LEJEUNE
** Last update Sun Apr 12 16:48:31 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char		*get_name(char *line)
{
  int		index_start;
  int		index_end;
  char		*name;

  line = epur_str(line);
  index_start = get_nindex_of(line, '"', 1);
  index_end = get_nindex_of(line, '"', 2);
  name = my_substr(line, index_start, index_end);
  return (name);
}

char		*get_comment(char *line)
{
  int		index_start;
  int		index_end;
  char		*comment;

  line = epur_str(line);
  index_start = get_nindex_of(line, '"', 1);
  index_end = get_nindex_of(line, '"', 2);
  comment = my_substr(line, index_start, index_end);
  return (comment);
}
