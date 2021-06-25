NAME			=	megaphone

SRCSDIR			=	srcs/
OBJSDIR			=	objs/
SRCS			=	megaphone.cpp

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror

OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))

$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $? 

clean:
					rm -f $(OBJS)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

test:
					./megaphone "shhhhh... I think the students are asleep..."
					./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
					./megaphone

.PHONY:				all clean fclean re test
