##
## Makefile for philo in /home/brout_m/rendu/system/PSU_2016_philo
##
## Made by Brout
## Login   <marc.brout@epitech.eu>
##
## Started on  Mon Jan 23 13:38:11 2017 Brout
## Last update Tue Mar 14 14:59:41 2017 duhieu_b
##

MAKE_DIR=	./

NAME=		trade

SRC_DIR=	./src/

SRC_FILES=	trade.cpp \
		Curve.cpp \
		Core.cpp \
		Com.cpp

SRC= 		$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ=		$(SRC:.cpp=.o)

INC=		./src/

CXX=		g++ -std=c++14

INC= 		-I./include

LDFLAGS=

ifeq ($(DEBUG), yes)
CFLAGS=	  	-g -W -Wall -Wextra -Werror $(INC)
else
CFLAGS=	  	-W -Wall -Wextra -Werror $(INC)
endif

ifeq ($(SANITIZE), yes)
CXX +=		-fsanitize=thread
endif

RM=		rm -rf

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(INC) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all
