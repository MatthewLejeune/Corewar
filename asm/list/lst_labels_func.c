/*
** lst_labels_func.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 20:17:16 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:21:29 2015 Matthew LEJEUNE
*/

#include "corewar.h"

t_labels	*create_new_label(char *label)
{
  t_labels	*new_label;

  if ((new_label = malloc(sizeof(t_labels))) == NULL)
    return (NULL);
  new_label->label = label;
  new_label->lst_cmd = NULL;
  new_label->next = NULL;
  new_label->prev = NULL;
  return (new_label);
}

int		add_label(t_labels **labels, char *label)
{
  t_labels	*new_label;
  t_labels	*cursor;

  if ((new_label = create_new_label(label)) == NULL)
    return (-1);
  if (*labels == NULL)
    *labels = new_label;
  else
    {
      cursor = *labels;
      while (cursor->next != NULL)
	cursor = cursor->next;
      cursor->next = new_label;
      new_label->prev = cursor;
    }
  return (0);
}

void		show_label_list(t_labels *list)
{
  t_labels	*display;

  display = list;
  while (display != NULL)
    {
      my_printf("\tLabel : %s\n", display->label);
      show_instruction_list(display->lst_cmd);
      display = display->next;
    }
}

t_labels	*search_in_labels(t_labels *labels, char *label)
{
  t_labels	*search;

  search = labels;
  while (search != NULL)
    {
      if (my_strncmp(label, search->label,
		     get_longest_string(label, search->label)) == 0)
	return (search);
      search = search->next;
    }
  return (NULL);
}
