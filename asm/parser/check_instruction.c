/*
** check_instruction.c for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Apr  9 11:07:30 2015 Matthew LEJEUNE
** Last update Sun Apr 12 19:29:26 2015 Matthew LEJEUNE
*/

#include "corewar.h"

static void	check_reg(char *arg, int cur_case)
{
  int		nb_reg;

  nb_reg = my_getnbr(arg);
  if (nb_reg > REG_NUMBER)
    my_exit("Maximum number or reg exceeded (1 - 16)", cur_case);
  else if (nb_reg <= 0)
    my_exit("Wrong registry name", cur_case);
}

static int	check_type(char *arg, int cur_case)
{
  arg = supress_spaces(arg);
  if (arg[0] == DIRECT_CHAR)
    return (T_DIR);
  else if (arg[0] == 'r')
    {
      check_reg(&arg[1], cur_case);
      return (T_REG);
    }
  else if (my_char_is_num(arg[0]) == 0 || arg[0] == '-'
	   || arg[0] == LABEL_CHAR)
    return (T_IND);
  else
    my_exit("Unrecognized arg type", cur_case);
  return (-1);
}

void	check_type_params(char **params, int cur_case, int cur_struct)
{
  int		found;
  int		cur_param;
  int		type;

  cur_param = -1;
  while (params[++cur_param])
    {
      found = 0;
      type = check_type(params[cur_param], cur_case);
      found = (type & op_tab[cur_struct].type[cur_param]) ? 1 : 0;
      if (found == 0)
	my_exit("Unexpected arg type", cur_case);
    }
}

static void	check_params(char *line, int cur_struct, int cur_case)
{
  int		nb_param;
  char		*line_param;
  int		index_end;
  char		**params;

  nb_param = get_nb_elem_split(line, SEPARATOR_CHAR);
  if (nb_param != op_tab[cur_struct].nbr_args)
    my_exit("Mismatched number of parameters given", cur_case);
  index_end = my_strlen(line);
  line_param = my_substr(line, get_nindex_of(line, ' ', 1), index_end);
  params = my_split(line_param, SEPARATOR_CHAR);
  check_type_params(params, cur_case, cur_struct);
}

void		check_instruction(char **tab)
{
  int		found;
  int		cur_case;
  int		cur_st;
  char		*inst;

  cur_case = -1;
  while (tab[++cur_case])
    {
      cur_st = -1;
      if (is_instruction(tab[cur_case]) != -1)
	{
	  found = 0;
	  inst = get_instruction(tab[cur_case]);
	  while (op_tab[++cur_st].mnemonique != 0 && found == 0)
	    {
	      if (my_strncmp(get_name_instruction(inst), op_tab[cur_st].mnemonique,
			     get_longest_string(get_name_instruction(inst),
						op_tab[cur_st].mnemonique)) == 0)
		{
		  check_params(inst, cur_st, cur_case);
		  found = 1;
		}
	    }
	}
    }
}
