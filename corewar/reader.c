/*
** reader.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 12 17:35:15 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:27:45 2015 Matthew LEJEUNE
*/

#include "corewar.h"

char	*reading(int fd, char *vm, int *a)
{
  while ((read(fd, &vm[*a], 1) != 0))
    {
      vm = realloc(vm, ((*a) + 2));
      (*a)++;
    }
  return (vm);
}

int 	check_champ_size(char *header)
{
  int	x;
  int	test;

  test = 0;
  x = 136;
  while (x < 140)
    {
      test = test << 8;
      test = test + header[x];
      if (header[x] < 0)
	test = test + 256;
      x++;
    }
  return (test);
}

void   	core(int ac, char *vm, char **av, int *start)
{
  int	fd;
  char	*header;
  int	i;
  int	*champ_size;
  static int a;

  i = 0;
  if ((champ_size = malloc(sizeof(int) * ac)) == NULL)
    return;
  while (++i < ac)
    {
      if ((header = malloc(sizeof(char) * HEADER)) == NULL)
	return;
      fd = open(av[i], O_RDONLY);
      if ((read(fd, header, HEADER)) < 0)
	return;
      start[i - 1] = a;
      champ_size[i - 1] = check_champ_size(header);
      vm = reading(fd, vm, &a);
      vm = fullboard(vm, &a, start, i);
      free(header);
    }
  if (a < MEMORY_SIZE)
    vm = fullboard2(vm, &a);
  print_vm(vm, ac, champ_size, start);
}

int	main(int ac, char **av)
{
  char	*vm;
  int	*start;

  if ((start = malloc(sizeof(int) * ac)) == NULL)
    return (1);
  if ((vm = malloc(sizeof(char) * 1)) == NULL)
    return (1);
  if (ac < 3 || ac > 6)
    exit(1);
  core(ac, vm, av, start);
  return (0);
}
