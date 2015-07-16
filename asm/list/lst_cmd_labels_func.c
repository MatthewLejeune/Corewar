/*
** lst_cmd_labels_func.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 20:34:40 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:21:00 2015 Matthew LEJEUNE
*/

#include "corewar.h"

static t_cmd_labels	*create_new_instruction(char *cmd, char **params)
{
  t_cmd_labels		*new_cmd;

  if ((new_cmd = malloc(sizeof(t_cmd_labels))) == NULL)
    return (NULL);
  new_cmd->cmd = cmd;
  new_cmd->params = params;
  new_cmd->next = NULL;
  new_cmd->prev = NULL;
  return (new_cmd);
}

int		add_instruction(t_cmd_labels **cmds, char *cmd, char **params)
{
  t_cmd_labels	*cursor;
  t_cmd_labels	*new_cmd;

  if ((new_cmd = create_new_instruction(cmd, params)) == NULL)
    return (-1);
  if (*cmds == NULL)
    *cmds = new_cmd;
  else
    {
      cursor = *cmds;
      while (cursor->next != NULL)
	cursor = cursor->next;
      cursor->next = new_cmd;
      new_cmd->prev = cursor;
    }
  return (0);
}

void		show_instruction_list(t_cmd_labels *cmds)
{
  int		cur_case;
  t_cmd_labels	*display;

  display = cmds;
  while (display != NULL)
    {
      cur_case = -1;
      my_printf("\t\tInstruction : %s\n\t\tParams : \n", display->cmd);
      while (display->params[++cur_case])
	my_printf("\t\t\t%s,\n", display->params[cur_case]);
      display = display->next;
    }
}

t_cmd_labels	*search_in_instruction(t_cmd_labels *instructions,
				       char *instruction)
{
  t_cmd_labels	*search;

  search = instructions;
  while (search != NULL)
    {
      if (my_strncmp(instruction, search->cmd, my_strlen(search->cmd)) == 0)
	return (search);
      search = search->next;
    }
  return (NULL);
}
