/*
** corewar.h for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar/include
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Mar 18 19:04:31 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:02:50 2015 Matthew LEJEUNE
*/

#ifndef __COREWAR_H__
#define __COREWAR_H__

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "vm.h"

/* DEFINE ERRORS */

#define MISSING_NAME		0
#define MISSING_COMMENT		1
#define SYNTAX_ERROR_NAME	2
#define SYNTAX_ERROR_COMMENT	3

/* END {DEFINE ERRORS} */

/* STRUCT ASM */

/* Labels instructions */

typedef struct	s_cmd_labels
{
  char			*cmd;
  char			**params;
  struct s_cmd_labels	*next;
  struct s_cmd_labels	*prev;
} t_cmd_labels;

/* Champion's labels */

typedef struct	s_labels
{
  char			*label;
  struct s_cmd_labels	*lst_cmd;
  struct s_labels	*next;
  struct s_labels	*prev;
} t_labels;

/* Champion struct */

typedef struct	s_champion
{
  char			*name;
  char			*comment;
  struct s_labels      	*lst_label;
  struct s_champion	*next;
  struct s_champion	*prev;
} t_champion;

/* END {STRUCT ASM} */

void		my_exit(char *, int);
int		get_nb_elem_split(char *, char);
void            check_name(char **);
void            check_comment(char **);
void            check_instruction(char **);
int             check_file(char **);
void            check_label(char **);
void		my_putchar(char);
int		my_putstr(char *);
char		*my_revstr(char *);
int		my_power_rec(int, int);
int		my_getnbr_base(char *, char *);
int		my_getnbr(char *);
int		my_strcmp(char *, char *);
int		do_it(t_cmd_labels *, int, t_labels *, int);
int		do_it2(t_cmd_labels *, int, int);
int		do_it3(t_cmd_labels *, int, t_labels *, int);
int		do_it_magic(char *, char *, int, t_labels *);
int		le_nom_de_la_fonction(char *, t_labels *);
int		champ_trad(int, t_champion *);
int		assembleur(int, int, int);
int		label_octet(t_cmd_labels *, int);
int		my_getnbr_final(char *);
int		print_param(t_cmd_labels *, int, int, int);
int		aff_res(int, int, int);
int		print_param1(t_cmd_labels *, int, int, int);
int		my_strncmp(char *, char *, int);
int		my_strlen(char *);
char		*my_realloc(char *, int);
char		*my_memset(char *, char, int);
char		**get_file_content(int);
int		get_index_elem_tab(char **, char *);
char		*my_substr(char *, int, int);
int		get_index_of(char *, char);
int		get_nindex_of(char *, char, int);
char		*get_next_line(int);
char		**my_realloc_double(char **, int);
int		get_nb_elem_tab(char **);
char		*get_name(char *);
int		my_char_is_num(char);
int		my_char_is_alpha(char);
char		*epur_str(char *);
char		*epur_str_brute(char *);
int		my_char_is_spec(char);
char		*get_comment(char *);
char		*get_label(char *);
char		*get_instruction(char *);
char		*get_name_instruction(char *);
int		is_label(char *);
int		is_instruction(char *);
char		**get_params(char *);
char		**my_split(char *, char);
t_champion	*get_list_champ(char **);
int		add_champion(t_champion **, char *, char *);
int		add_label(t_labels **, char *);
void		show_label_list(t_labels *);
void		show_instruction_list(t_cmd_labels *);
int		add_instruction(t_cmd_labels **, char *, char **);
void		show_champions(t_champion *);
t_labels	*search_in_labels(t_labels *, char *);
char		*supress_spaces(char *);
int		get_longest_string(char *, char *);
int		champ_trad(int, t_champion *);
void		check_extension(int, char **);

#endif
