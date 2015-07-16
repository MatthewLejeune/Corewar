/*
** my_memset.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 23:02:25 2015 Matthew LEJEUNE
** Last update Wed Mar 18 23:04:24 2015 Matthew LEJEUNE
*/

char		*my_memset(char *str, char c, int size)
{
  int		cur_char;

  cur_char = -1;
  while (++cur_char < size)
    str[cur_char] = c;
  return (str);
}
