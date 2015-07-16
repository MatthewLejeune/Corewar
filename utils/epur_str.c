/*
** my_epurstr.c for epur_str in /home/roy_n
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Wed Apr  1 14:57:04 2015 Nathan Roy
** Last update Sat Apr 11 17:23:44 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char		*epur_str(char *str)
{
  int		i;
  char		*str2;
  int		p;

  p = -1;
  i = -1;
  if ((str2 = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[++i] == ' ' || str[i] == '\t');
  while (str[i] != 0)
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[++i] == ' ' || str[i] == '\t');
	  if (str[i] != 0)
	    str2[++p] = ' ';
	}
      else
	{
	  str2[++p] = str[i];
	  i++;
	}
    }
  str2[++p] = 0;
  return (str2);
}

char		*supress_spaces(char *str)
{
  int		cur_char;
  int		cur_char_new;
  char		*new_str;

  cur_char = -1;
  cur_char_new = -1;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if (str)
    {
      while (str[++cur_char])
	if (str[cur_char] != ' ')
	  new_str[++cur_char_new] = str[cur_char];
      free(str);
    }
  new_str[++cur_char_new] = '\0';
  return (new_str);
}
