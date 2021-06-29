NAME			=	violence

SRCSDIR			=	./
OBJSDIR			=	objs/

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror

INCLUDES		=	./

SRCS			=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))

$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp
					@ mkdir -p objs
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $? -I$(INCLUDES)

info:
					echo $(SRCS)
					echo $(OBJS)

clean:
					rm -f $(OBJS)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re test
