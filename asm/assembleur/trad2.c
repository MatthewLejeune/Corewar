/*
** trad2.c for trad in /home/roy_n/CPE_2014_corewar/asm/assembleur
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sun Apr 12 15:32:19 2015 Nathan Roy
** Last update Sun Apr 12 16:21:40 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int     my_getnbr_final(char *str)
{
  int result;

  if (str[1] == 'x')
    result = my_getnbr_base(&str[2], "0123456789abcdef");
  else
    result = my_getnbr(str);
  return (result);
}

int     le_nom_de_la_fonction(char *label, t_labels *list)
{
  struct s_labels *tmp;
  int   i;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      if (label != NULL)
        {
          if (my_strcmp(label, tmp->label) == 0)
            return (i);
        }
      i = label_octet(tmp->lst_cmd, i);
      tmp = tmp->next;
    }
  return (i);
}

int     do_it2(t_cmd_labels *cmd_tmp, int pos, int fd)
{
  int   res;
  int   i;
  int   nb;

  i = 0;
  nb = 128;
  res = 0;
  while (cmd_tmp->params[i] != NULL)
    {
      if (cmd_tmp->params[i][0] == 'r')
        res = res + (nb / 2);
      else if (cmd_tmp->params[i][0] == '%')
        res = res + nb;
      else
        {
          res = res + nb;
          res = res + (nb / 2);
        }
      nb = (nb / 2) / 2;
      i++;
    }
  pos = pos + assembleur(res, 1, fd);
  return (pos);
}

int     print_param1(t_cmd_labels *cmd_tmp, int fd, int pos, int i)
{
  int nb;
  int res;

  res = 0;
  nb = 0x01000000;
  res = my_getnbr_final(&cmd_tmp->params[i][1]);
  while (nb > 0)
    {
      if (res >= nb)
        {
          pos = pos + assembleur(res / nb, 1, fd);
          res = res % nb;
        }
      else
        pos = pos + assembleur(0, 1, fd);
      nb = nb / 0x100;
    }
  return (pos);
}

int     aff_res(int pos, int res, int fd)
{
  int nb;

  nb = 0x0100;
  while (nb > 0)
    {
      if (res >= nb)
        {
          pos = pos + assembleur(res / nb, 1, fd);
          res = res % nb;
        }
      else
        pos = pos + assembleur(0, 1, fd);
      nb = nb /0x100;
    }
  return (pos);
}
