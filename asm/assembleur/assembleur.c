/*
** assembleur.c for assembleur in /home/roy_n/CPE_2014_corewar/asm/assembleur
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Thu Mar 19 14:07:33 2015 Nathan Roy
** Last update Sun Apr 12 19:17:40 2015 Matthew LEJEUNE
*/

#include "corewar.h"

int	do_it(t_cmd_labels *cmd_tmp, int fd, t_labels *list, int pos)
{
  int	i;

  i = 0;
  while (my_strcmp(cmd_tmp->cmd, op_tab[i].mnemonique)
	 != 0 && op_tab[i].mnemonique != 0)
    i++;
  if (op_tab[i].mnemonique != 0)
    {
      pos = pos + assembleur(op_tab[i].code, 1, fd);
      if (cmd_tmp->params[1] != NULL)
	pos = do_it2(cmd_tmp, pos, fd);
    }
  else
    return (pos + assembleur(0, 1, fd));
  pos = do_it3(cmd_tmp, fd, list, pos);
  return (pos);
}

int	do_it_magic2(int nb, char *comment, int fd, t_labels *list)
{
  int	nb2;
  int	res;

  nb2 = 0x01000000;
  res = le_nom_de_la_fonction(NULL, list);
  while (nb2 > 0)
    {
      if (res >= nb2)
	{
	  assembleur(res / nb2, 1, fd);
	  res = res % nb2;
	}
      else
	assembleur(0, 1, fd);
      nb2 = nb2 / 0x100;
    }
  write(fd, comment, my_strlen(comment));
  while (nb > 0)
    {
      assembleur(0, 1, fd);
      nb--;
    }
  assembleur(0, 4, fd);
  return (0);
}

int	do_it_magic(char *name, char *comment, int fd, t_labels *list)
{
  int	nb;
  int	fuck;

  nb = PROG_NAME_LENGTH - my_strlen(name);
  assembleur(0, 1, fd);
  fuck = 0xea;
  assembleur(fuck, 1, fd);
  fuck = 0x83;
  assembleur(fuck, 1, fd);
  fuck = 0xf3;
  assembleur(fuck, 1, fd);
  write(fd, name, my_strlen(name));
  while (nb > 0)
    {
      assembleur(0, 1, fd);
      nb--;
    }
  nb = COMMENT_LENGTH - my_strlen(comment);
  assembleur(0, 4, fd);
  do_it_magic2(nb, comment, fd, list);
  return (0);
}
