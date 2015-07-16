/*
** my_char_is_spec.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Mar 19 16:47:14 2015 Matthew LEJEUNE
** Last update Thu Mar 19 16:52:59 2015 Matthew LEJEUNE
*/

int		my_char_is_spec(char c)
{
  if (c >= 33 && c <= 126)
    return (0);
  return (-1);
}
