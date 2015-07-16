/*
** trad3.c for trad.c in /home/roy_n/CPE_2014_corewar/asm/assembleur
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sun Apr 12 15:33:33 2015 Nathan Roy
** Last update Sun Apr 12 16:21:52 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int     calc_modul(t_cmd_labels *cmd_tmp, int pos_tmp, t_labels *list, int i)
{
  int res;

  res = 0;
  if (cmd_tmp->params[i][0] == '%' && cmd_tmp->params[i][1] == ':')
    {
      res = le_nom_de_la_fonction(&cmd_tmp->params[i][2], list)
        - pos_tmp;
      if (res < 0)
        res = 0xffff + res + 1;
    }
  else if (cmd_tmp->params[i][0] == '%')
    {
      res = my_getnbr_final(&cmd_tmp->params[i][1]);
      if (res < 0)
        res = 0xffff + res + 1;
    }
  else
    res = my_getnbr_final(&cmd_tmp->params[i][0]);
  return (res);
}

int     calc_modul_o(t_cmd_labels *cmd_tmp, int o, int i)
{
  int res;

  if (cmd_tmp->params[i][0] == '%' && cmd_tmp->params[i][1] == ':')
    o = i + 1;
  else if (cmd_tmp->params[i][0] == '%')
    {
      res = my_getnbr_final(&cmd_tmp->params[i][1]);
      if (res < 0)
        o = i + 1;
    }
  return (o);
}

int     do_it3_o(t_cmd_labels *cmd_tmp, int i, int o)
{
  if (i != o && o != 42)
    o = 0;
  if (cmd_tmp->params[i + 1] != NULL)
    if (cmd_tmp->params[i + 1][0] == '%')
      o = i + 2;
  return (o);
}

int     do_it3_o2(t_cmd_labels *cmd_tmp, int o, int i)
{
  if (cmd_tmp->params[i][0] == 'r')
    o = o;
  else if (cmd_tmp->params[i][0] == '%' && cmd_tmp->params[i][1] != ':' &&
           o == 0 && cmd_tmp->params[i][1] != '-')
    o = o;
  else
    o = calc_modul_o(cmd_tmp, o, i);
  return (o);
}

int     do_it3(t_cmd_labels *cmd_tmp, int fd, t_labels *list, int pos)
{
  int   i;
  int   o;
  int   pos_tmp;

  o = 0;
  pos_tmp = pos - 1;
  if (cmd_tmp->params[1] != NULL)
    pos_tmp = pos - 2;
  if (my_strcmp(cmd_tmp->cmd, "zjmp") == 0)
    o = 42;
  i = 0;
  while (cmd_tmp->params[i] != NULL)
    {
      o = do_it3_o(cmd_tmp, i, o);
      if (cmd_tmp->params[i][0] == 'r')
        pos = pos + assembleur(my_getnbr_final(&cmd_tmp->params[i][1]), 1, fd);
      else if (cmd_tmp->params[i][0] == '%' && cmd_tmp->params[i][1] != ':' &&
               o == 0 && cmd_tmp->params[i][1] != '-')
        pos = print_param1(cmd_tmp, fd, pos, i);
      else
	pos = aff_res(pos, calc_modul(cmd_tmp, pos_tmp, list, i), fd);
      o = do_it3_o2(cmd_tmp, o, i);
      i++;
    }
  return (pos);
}
