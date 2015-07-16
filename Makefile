##
## Makefile for CoreWar in /home/lejeun_m/Projets/CPE_2014_corewar
## 
## Made by Matthew LEJEUNE
## Login   <lejeun_m@epitech.net>
## 
## Started on  Wed Mar 18 22:17:08 2015 Matthew LEJEUNE
## Last update Sun Apr 12 19:32:04 2015 Matthew LEJEUNE
##

SRC_ASM=	asm/list/lst_champion_func.c \
		asm/list/lst_cmd_labels_func.c \
		asm/list/lst_labels_func.c \
		asm/main.c \
		asm/assembleur/assembleur.c \
		asm/assembleur/trad.c \
		asm/assembleur/trad2.c \
		asm/assembleur/trad3.c \
		asm/lexer/get_basic_champ_info.c \
		asm/lexer/fill_lists.c \
		asm/lexer/get_file_content.c \
		asm/lexer/get_infos_labels.c \
		asm/lexer/get_infos_instructions.c \
		asm/parser/check_instruction.c \
		asm/parser/check_label.c \
		asm/parser/check_name.c \
		asm/parser/check_extension.c

SRC_COREWAR=	corewar/reader.c \
		corewar/print_vm.c

SRC_UTILS=	utils/get_index_elem_tab.c \
		utils/get_next_line.c \
		utils/my_strncmp.c \
		utils/op.c \
		utils/get_index_of.c \
		utils/my_realloc.c \
		utils/my_strlen.c \
		utils/my_substring.c \
		utils/my_memset.c \
		utils/get_nb_elem_tab.c \
		utils/my_char_is_num.c \
		utils/my_char_is_alpha.c \
		utils/my_char_is_spec.c \
		utils/epur_str.c \
		utils/my_exit.c \
		utils/my_split.c \
		utils/my_putchar.c \
		utils/my_putstr.c \
		utils/my_strcmp.c \
		utils/my_getnbr_base.c \
		utils/my_power_rec.c \
		utils/my_revstr.c \
		utils/my_getnbr.c \
		utils/my_printf.c \
		utils/my_putnbr_base.c \
		utils/my_put_nbr.c \
		utils/my_putnbr_long.c \
		utils/my_putnbr_unsigned.c \
		utils/putnbr_base_unsigned.c \
		utils/get_longest_string.c

OBJ_ASM=	$(SRC_ASM:.c=.o)
OBJ_COREWAR=	$(SRC_COREWAR:.c=.o)
OBJ_UTILS=	$(SRC_UTILS:.c=.o)

NAME_ASM=	asm/asm
NAME_COREWAR=	corewar/corewar

CC=		cc
CFLAGS=		-Wall -Wextra -Werror -pedantic
CFLAGS+=	-I include/

all:			$(OBJ_UTILS) $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM):		$(OBJ_ASM)
			$(CC) $(CFLAGS) -o $(NAME_ASM) $(SRC_ASM) $(SRC_UTILS)

$(NAME_COREWAR):	$(OBJ_COREWAR)
			$(CC) $(CFLAGS) -o $(NAME_COREWAR) $(SRC_COREWAR) $(SRC_UTILS)

clean:
			rm -rf $(OBJ_UTILS) $(OBJ_ASM) $(OBJ_COREWAR)

fclean:			clean
			rm -rf $(NAME_ASM) $(NAME_COREWAR)

re:			fclean all
