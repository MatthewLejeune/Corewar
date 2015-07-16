/*
** get_infos_instructions.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Apr  1 19:10:31 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:20:24 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int		is_instruction(char *line)
{
  int		cur_char;
  int		pos;

  cur_char = -1;
  if (is_label(line) != -1)
    {
      pos = get_index_of(line, ':');
      line = my_substr(line, pos, my_strlen(line));
    }
  line = epur_str(line);
  while (line[++cur_char])
    if (cur_char != 0)
      if (my_char_is_alpha(line[cur_char]) == 0 && line[0] != '.'
	  && line[0] != '\0')
	return (0);
  return (-1);
}

char		*get_instruction(char *line)
{
  int		start_index;

  start_index = 0;
  if (is_label(line) != -1)
    {
      start_index = get_index_of(line, ':');
      line = my_substr(line, start_index, my_strlen(line));
    }
  line = epur_str(line);
  return (line);
}

char		*get_name_instruction(char *line)
{
  int		index_end;
  char		*instruction;

  if (is_label(line) != -1)
    line = my_substr(line, get_index_of(line, ':'), my_strlen(line));
  line = epur_str(line);
  if ((index_end = get_index_of(line, ' ')) == -1)
    return (NULL);
  instruction = my_substr(line, -1, index_end);
  return (instruction);
}

char		**get_params(char *instruction)
{
  int		index_start;
  int		index_end;
  int		cur_char;
  char		*param;
  char		**params;

  cur_char = -1;
  index_start = get_nindex_of(instruction, ' ', 1);
  index_end = my_strlen(instruction);
  param = my_substr(instruction, index_start, index_end);
  param = supress_spaces(param);
  while (param[++cur_char])
    if (param[cur_char] == ';' || param[cur_char] == COMMENT_CHAR)
      param[cur_char] = '\0';
  params = my_split(param, ',');
  return (params);
}
