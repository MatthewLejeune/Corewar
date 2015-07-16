/*
** get_nb_elem_tab.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 23:08:46 2015 Matthew LEJEUNE
** Last update Thu Mar 19 14:07:47 2015 Matthew LEJEUNE
*/

int		get_nb_elem_tab(char **tab)
{
  int		cur_case;

  cur_case = 0;
  if (tab)
    while (tab[cur_case])
      cur_case++;
  return (cur_case);
}
