/*
** lst_champion_func.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 20:47:37 2015 Matthew LEJEUNE
** Last update Sun Apr 12 18:01:20 2015 Matthew LEJEUNE
*/

#include "corewar.h"

t_champion	*create_new_champion(char *name, char *comment)
{
  t_champion	*new_champion;

  if ((new_champion = malloc(sizeof(t_champion))) == NULL)
    return (NULL);
  new_champion->name = name;
  new_champion->comment = comment;
  new_champion->lst_label = NULL;
  new_champion->next = NULL;
  new_champion->prev = NULL;
  return (new_champion);
}

int		add_champion(t_champion **champions, char *name, char *comment)
{
  t_champion	*new_champion;
  t_champion	*cursor;

  if ((new_champion = create_new_champion(name, comment)) == NULL)
    return (-1);
  if (*champions == NULL)
    *champions = new_champion;
  else
    {
      cursor = *champions;
      while (cursor->next != NULL)
	cursor = cursor->next;
      cursor->next = new_champion;
      new_champion->prev = cursor;
    }
  return (0);
}

void		show_champions(t_champion *champion)
{
  t_champion	*display;

  display = champion;
  while (display != NULL)
    {
      my_printf("%s\n", display->name);
      my_printf("%s\n", display->comment);
      show_label_list(display->lst_label);
      display = display->next;
    }
}

t_champion	*search_in_champion(t_champion *champion, char *name)
{
  t_champion	*search;

  search = champion;
  while (search != NULL)
    {
      if (my_strncmp(name, search->name, my_strlen(search->name)) == 0)
	return (search);
      search = search->next;
    }
  return (NULL);
}
