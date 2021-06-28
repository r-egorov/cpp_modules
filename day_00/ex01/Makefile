NAME			=	phonebook

SRCSDIR			=	srcs/
OBJSDIR			=	objs/
INCLUDES		=	includes/

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	Phonebook.cpp main.cpp Interface.cpp Contact_class.cpp
OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))

$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp
					$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

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
