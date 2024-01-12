#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -g
#=================== NAME ===================#
NAME = push_swap
#============= MANDATORY SOUCES =============#
SRCS = SRCS/main.c \
	SRCS/action_push.c \
	SRCS/action_reverse_rotate.c \
	SRCS/action_rotate.c \
	SRCS/action_swap.c \
	SRCS/check.c \
	SRCS/cost.c \
	SRCS/index_target_handle.c \
	SRCS/link_list.c \
	SRCS/median.c \
	SRCS/move.c \
	SRCS/push_swap.c \
	SRCS/sort.c \
	SRCS/stack_utils.c \
	SRCS/utils.c 

#=============== BONUS SOURCES ==============#
#BONUS = 

#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJM = $(SRCS:.c=.o)

#================ BONUS PART ================#
#OBJB = $(BONUS:.c=.o)

#================= MAKE NAME ================#

LIBFT = Libft/libft.a

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C Libft all

%.o : %.c SRCS/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJB) $(LIBFT)
	$(CC) $(FLAGS) $(OBJB) $(LIBFT) -o $(NAME)

$(NAME) : $(OBJM) $(LIBFT)
	$(CC) $(FLAGS) $(OBJM) $(LIBFT) -o $(NAME)
	
clean :
	@ $(MAKE) -C Libft clean
	rm -rf $(OBJM) $(OBJB)

fclean :
	@ $(MAKE) -C Libft fclean
	rm -rf $(NAME) $(OBJM) $(OBJB)

re : fclean all

.PHONY : all clean fclean re bonus
