/*
** check_extension.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 12 16:00:40 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:03:13 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void		check_extension(int argc, char *argv[])
{
  int		cur_case;
  char		*extension;

  cur_case = 0;
  while (++cur_case < argc)
    {
      extension = my_substr(argv[cur_case], my_strlen(argv[cur_case]) - 3,
			    my_strlen(argv[cur_case]));
      if (my_strncmp(extension, ".s", 2) != 0)
	my_exit("File extension not supported by compiler", 0);
    }
}
