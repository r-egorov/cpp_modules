NAME			=	interface

SRCSDIR			=	srcs/
OBJSDIR			=	objs/

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

INCLUDES		=	includes/

SRCS			=	AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp
OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))
DEPS			=	$(OBJS:%.o=%.d)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $? -I$(INCLUDES)

-include $(DEPS)
$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp Makefile
					@ mkdir -p $(OBJSDIR)
					$(CC) $(CFLAGS) -MMD -c $< -o $@ -I$(INCLUDES)
info:
					echo $(DEPS)
					echo $(SRCS)
					echo $(OBJS)

clean:
					rm -rf $(OBJSDIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re test
