NAME			=	account_test

SRCSDIR			=	./
OBJSDIR			=	objs/

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	Account.cpp tests.cpp
OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))

$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp
					@ mkdir -p objs
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $? 

info:
					echo $(SRCS)
					echo $(OBJS)

clean:
					rm -f $(OBJS)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re test
