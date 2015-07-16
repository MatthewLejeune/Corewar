/*
** fill_lists.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat Mar 21 15:36:16 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:19:30 2015 Matthew LEJEUNE
*/

#include "corewar.h"

static void	set_labels_instruction(t_labels **labels, char **file_content)
{
  int		cur_case;
  t_labels	*labls;

  cur_case = -1;
  labls = *labels;
  while (file_content[++cur_case])
    {
      if (is_label(file_content[cur_case]) != -1)
	labls = search_in_labels(labls, get_label(file_content[cur_case]));
      if (is_instruction(file_content[cur_case]) != -1)
	add_instruction(&(labls->lst_cmd),
			get_name_instruction(file_content[cur_case]),
			get_params(get_instruction(file_content[cur_case])));
    }
}

static void	set_champ_labels(t_labels **labels, char **file_content)
{
  int		cur_case;

  cur_case = -1;
  while (file_content[++cur_case])
    {
      if (is_instruction(file_content[cur_case]) != -1 &&
	  is_label(file_content[cur_case]) != -1 && !(*labels))
	add_label(labels, ".");
      if (is_label(file_content[cur_case]) != -1)
	add_label(labels, get_label(file_content[cur_case]));
    }
}

t_champion	*get_list_champ(char **file_content)
{
  char		*name;
  char		*comment;
  t_champion	*champion;

  champion = NULL;
  if ((name = get_name(file_content[0])) == NULL)
    return (champion);
  if ((comment = get_comment(file_content[1])) == NULL)
    return (champion);
  if (add_champion(&champion, name, comment) == -1)
    return (NULL);
  set_champ_labels(&champion->lst_label, file_content);
  set_labels_instruction(&champion->lst_label, file_content);
  show_champions(champion);
  return (champion);
}
