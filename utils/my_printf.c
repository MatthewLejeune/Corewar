/*
** my_printf.c for printf in /home/boiven_d/PSU_2014_my_printf
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Fri Nov 14 13:57:22 2014 David Boivent
** Last update Sun Apr 12 17:44:51 2015 Matthew LEJEUNE
*/

#include "corewar.h"
/*
void	my_putstrascii(char *str)
{
  int	i;
  int	s;

  i = 0;
  while (str[i])
    {
      s = (str[i] < 8) ? str[i], my_putstr("\\00"),
      putn_base(s, "01234567"):
	str[i] > 7 && str[i] < 17 ? s = str[i], my_putstr("\\0"),
	putn_base(s, "01234567"):
	str[i] == 127 ? s = str[i], my_putchar(92),
  putn_base(s, "01234567"):
	my_putchar(str[i]);
      i++;
    }
}
*/
void	adress(void *str)
{
  unsigned long	a;
  char result[12];
  char *base;
  int	i;

  i = 11;
  a = (unsigned long) str;
  base = "0123456789abcdef";
  while ((a / 16) > 0)
    {
      result[i] = base[a%16];
      a = a / 16;
      i--;
    }
  result[i] = base[a%16];
  my_putstr("0x");
  while (i < 12)
    {
      my_putchar(result[i]);
      i++;
    }
}

int	my_printf2(int i, va_list ap, char *str)
{
  if (str[i + 1] == 's')
    my_putstr(va_arg(ap, char*));
  else if (str[i + 1] == 'c')
    my_putchar(va_arg(ap, int));
  else if (str[i + 1] == 'p')
    adress(va_arg(ap, void*));
  else if (str[i + 1] == 'd' || str[i + 1] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (str[i + 1] == 'x')
    putn_base_unsi(va_arg(ap, int), "0123456789abcdef");
  else if (str[i + 1] == 'X')
    putn_base_unsi(va_arg(ap, int), "0123456789ABCDEF");
  else if (str[i + 1] == 'b')
    putn_base_unsi(va_arg(ap, unsigned int), "01");
  else if (str[i + 1] == 'o')
    putn_base_unsi(va_arg(ap, unsigned int), "01234567");
  else if (str[i + 1] == 'u')
    my_putnbr_unsigned(va_arg(ap, unsigned int));
  else if (str[i + 1] == ' ')
    my_putstr("% ");
  else
    my_putchar('%');
  return (0);
}

int	my_printf(char *str, ...)
{
  int   i;
  va_list ap;

  va_start(ap, str);
  i = 0;
  while (str[i])
    {
      if (str[i] == '%')
	{
	  if (str[i + 1] == '\0')
	    i = i + 3;
	  else if (str[i + 1] == 'l' && str[i + 2] == 'd')
	    {
	      my_putnbr_long(va_arg(ap, long));
	      i++;
	    }
	  else
	    my_printf2(i, ap, str);
	  i = i + 2;
	}
      else
	my_putchar(str[i++]);
    }
  va_end(ap);
  return (0);
}
