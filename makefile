CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME = push_swap

CHECKER = checker

LIBFT = libft/libft.a

SRCS = command_list.c connect_by_list.c list_utils.c push_swap.c \
		sort_case2.c sort_case3.c sort_case5.c sort_case6.c \
		sort_case_over6.c print_stack.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT) :
		make -C libft

clean :
		make clean -C libft
		$(RM) $(OBJS)
		$(RM) $(OBJS2)

fclean : clean
		$(RM) $(LIBFT)
		$(RM) $(NAME)

re : fclean all