/*
** trad.c for trad in /home/roy_n/CPE_2014_corewar/asm/assembleur
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sun Apr 12 15:29:36 2015 Nathan Roy
** Last update Sun Apr 12 18:52:02 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int     assembleur(int i, int oct, int fd)
{
  write(fd, &i, oct);
  return (oct);
}

int     champ_trad(int fd, t_champion *champ)
{
  t_labels      *lab_tmp;
  t_cmd_labels  *cmd_tmp;
  int   pos;

  pos = 0;
  lab_tmp = champ->lst_label;
  do_it_magic(champ->name, champ->comment, fd, lab_tmp);
  while (lab_tmp != NULL)
    {
      cmd_tmp = lab_tmp->lst_cmd;
      while (cmd_tmp != NULL)
        {
          pos = do_it(cmd_tmp, fd, champ->lst_label, pos);
          cmd_tmp = cmd_tmp->next;
        }
      lab_tmp = lab_tmp->next;
    }
  return (0);
}

int     cmd_octet2(int p, char **param, int i, int o)
{
  while (param[p] != NULL)
    {
      if (o != p && o != 42)
        o = 0;
      if (param[p + 1] != NULL)
        {
          if (param[p + 1][0] == '%')
            o = p + 2;
        }
      if (param[p][0] == '%' && param[p][1] != ':' && o == 0 && param[p][1]
          != '-')
        i = i + 4;
      else if (param[p][0] == 'r')
        i++;
      else
        {
          if (param[p][0] == '%')
            o = p + 1;
          else if (param[p][0] == '%' && param[p][1] == ':')
            o = p + 1;
          i = i + 2;
        }
      p++;
    }
  return (i);
}

int     cmd_octet(char *name, char **param, int i)
{
  int   p;
  int   o;

  o = 0;
  p = 0;
  while (my_strcmp(name, op_tab[p].mnemonique) != 0 && op_tab[p].mnemonique
         != 0)
    p++;
  if (op_tab[p].mnemonique == 0)
    {
      i++;
      return (i);
    }
  p = 0;
  i++;
  if (param[1] != NULL)
    i++;
  else if (my_strcmp(name, "zjmp") == 0)
    o = 42;
  i = cmd_octet2(p, param, i, o);
  return (i);
}

int     label_octet(t_cmd_labels *list, int i)
{
  struct s_cmd_labels *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      i = cmd_octet(tmp->cmd, tmp->params, i);
      tmp = tmp->next;
    }
  return (i);
}
