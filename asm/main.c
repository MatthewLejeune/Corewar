/*
** main.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 22:14:56 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:01:22 2015 Matthew LEJEUNE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "corewar.h"

char		*str_cor(char *argv)
{
  int		i;
  char		*str;
  int		p;

  p = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(argv) + 3))) == NULL)
    return (NULL);
  i = my_strlen(argv);
  while (argv[i] != '/' && i > 0)
    i--;
  if (argv[i] == '/')
    i++;
  while (argv[i + 1] != 0)
    {
      str[p] = argv[i];
      i++;
      p++;
    }
  str[p] = 'c';
  str[p + 1] = 'o';
  str[p + 2] = 'r';
  str[p + 3] = '\0';
  return (str);
}

int		check_file(char **tab)
{
  check_name(tab);
  check_comment(tab);
  check_label(tab);
  check_instruction(tab);
  return (0);
}

int		main(int argc, char *argv[])
{
  int		fd;
  char		**tab;
  char		*str;

  argv = argv;
  if (argc < 2)
    {
      my_printf("Program needs more than one argument to work\n");
      return (-1);
    }
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
      my_printf("%s : no such file or directory\n", argv[1]);
      return (-1);
    }
  check_extension(argc, argv);
  tab = get_file_content(fd);
  close(fd);
  check_file(tab);
  str = str_cor(argv[1]);
  fd = open(str, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  champ_trad(fd, get_list_champ(tab));
  close(fd);
  return (0);
}
