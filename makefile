NAME = pushswap.a

SRCS = command_list.c connect_by_list.c list_utils.c push_swap.c \
		sort_case2.c sort_case3.c sort_case5.c sort_case_over_six.c \
		print_stack.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc -c
RM = rm -f
AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re