CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCLUDES = includes
SRCS_PATH = ./srcs/
LIBFT_PATH = ./libft/

SRCS = $(SRCS_PATH)command_list.c $(SRCS_PATH)connect_by_list.c $(SRCS_PATH)list_utils.c $(SRCS_PATH)print_stack.c \
		$(SRCS_PATH)sort_case2.c $(SRCS_PATH)sort_case3.c $(SRCS_PATH)sort_case5.c $(SRCS_PATH)sort_case6.c \
		$(SRCS_PATH)sort_case_over6.c $(SRCS_PATH)utils.c
OBJS = $(SRCS:.c=.o)

LIBFTMAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG = -L$(LIBFT_PATH) -lft

all : $(NAME)

$(NAME) : $(OBJS)
		$(LIBFTMAKE)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAG) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		$(LIBFTMAKE) clean
		$(RM) $(OBJS)

fclean : clean
		$(LIBFTMAKE) fclean
		$(RM) $(NAME) $(SRCS_OBJS)

re : fclean all