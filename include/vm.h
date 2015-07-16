/*
** my_printf.h for my_printf in /home/boiven_d/
** 
** Made by David Boivent
** Login   <boiven_d@epitech.net>
** 
** Started on  Sat Jan 10 14:08:02 2015 David Boivent
** Last update Sun Apr 12 18:54:51 2015 Matthew LEJEUNE
*/

#ifndef READER_H_
# define READER_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define WHITE "\x1b[39m"
#define B_U "\x1b[36m"
#define CLEAR "\033\143"
#define RESET "\x1b[0m"

#define HEADER 2192
#define MEMORY_SIZE 6144
#define CHAMP_SIZE 1536

char	*reading(int, char *, int *);
char	*fullboard(char *, int *, int *, int);
char	*fullboard2(char *, int *);
void	check_color(int *, int, int, int *);
void	print_nbr(int, char *);
void	print_vm(char *, int, int *, int *);
int 	check_champ_size(char *);
void   	core(int, char *, char **, int *);
int	my_getnbr(char *);
void	my_putstrascii(char *);
void	adress(void *);
int	my_printf2(int, va_list, char *);
int	my_printf(char *, ...);
int     last_while(int, int, int);
int     my_put_nbr(int);
int	count_base(char *);
int	my_putnbr_base2(int, char *);
int	my_putnbr_base(int, char *);
long	last_while_long(long, long, long);
long	my_putnbr_long(long);
unsigned int	last_while_unsigned(unsigned int);
unsigned int	my_putnbr_unsigned(unsigned int);
unsigned int	count_base_unsi(char *);
unsigned int    putn_base2_unsi(unsigned int, char *);
unsigned int    putn_base_unsi(unsigned int, char *);

#endif
