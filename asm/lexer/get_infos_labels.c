/*
** code_parser.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Mar 19 19:02:17 2015 Matthew LEJEUNE
** Last update Sun Apr 12 16:49:16 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		is_label(char *line)
{
  int		pos;

  pos = -1;
  if (line[0] == '\t')
    return (-1);
  if ((pos = get_index_of(line, ':')) == -1)
    return (-1);
  if (line[pos + 1] != ' ' && line[pos + 1] != '\t')
    return (-1);
  return (0);
}

char		*get_label(char *line)
{
  int		index_start;
  int		index_end;
  char		*label;

  index_start = -1;
  index_end = get_nindex_of(line, ':', 1);
  label = my_substr(line, index_start, index_end);
  return (label);
}
