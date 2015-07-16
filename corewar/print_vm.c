/*
** print_vm.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 12 17:33:09 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:27:27 2015 Matthew LEJEUNE
*/

#include "corewar.h"

void	check_color(int *champ_size, int x, int ac, int *start)
{
  if (x <= CHAMP_SIZE && x < champ_size[0])
    my_printf(RED);
  if (x >= CHAMP_SIZE - 1 && x < champ_size[1] + (CHAMP_SIZE - 1))
    my_printf(GREEN);
  if (x >= (CHAMP_SIZE - 1) * 2
      && x < champ_size[2] + (CHAMP_SIZE - 1) * 2 && ac > 3)
    my_printf(BLUE);
  if (x >= (CHAMP_SIZE - 1) * 3
      && x < champ_size[2] + (CHAMP_SIZE - 1) * 3 && ac > 4)
    my_printf(YELLOW);
  if (x == start[0])
    my_printf(B_U);
  if (x == start[1])
    my_printf(B_U);
  if (x == start[2])
    my_printf(B_U);
  if (x == start[3])
    my_printf(B_U);
}

void	print_nbr(int x, char *vm)
{
  int	test;
  int	test2;

  test = 0;
  test2 = 0;
  if (vm[x] < 0)
    {
      vm[x] = vm[x] * (-1);
      if (vm[x] != -128)
	test = 128 - vm[x];
      else
	test = 0;
      test2 = 128 + test;
      my_printf("%x ", test2);
    }
  else
    my_printf("%x ", vm[x]);
}

void	print_vm(char *vm, int ac, int *champ_size, int *start)
{
  int	x;

  x = 0;
  while (x < MEMORY_SIZE)
    {
      my_printf(RESET);
      check_color(champ_size, x, ac, start);
      if (vm[x] / 16 == 0 && vm[x] >= 0)
	my_printf("0");
      if (vm[x] == 0)
	my_printf("0 ");
      else
	print_nbr(x, vm);
      x++;
      if (x % 16 == 0)
	my_printf("\n");
    }
  my_printf("\n");
  my_printf(RESET);
}

char	*fullboard(char *vm, int *a, int *start, int i)
{
  int	size;
  int	st;

  size = 0;
  st = start[i - 1];
  while (st <= (*a))
    {
      size++;
      st++;
    }
  if (size == CHAMP_SIZE)
    return (NULL);
  else if (size < CHAMP_SIZE)
    {
      while (size != CHAMP_SIZE)
	{
	  vm = realloc(vm, ((*a) + 2));
	  vm[*a] = 0;
	  (*a)++;
	  size++;
	}
    }
  return (vm);
}

char	*fullboard2(char *vm, int *a)
{
  while (*a != MEMORY_SIZE)
    {
      vm = realloc(vm, ((*a) + 2));
      vm[*a] = 0;
      (*a)++;
    }
  return (vm);
}
