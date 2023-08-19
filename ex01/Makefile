# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 18:03:28 by makacem           #+#    #+#              #
#    Updated: 2023/08/19 18:07:48 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
HEADER =  RPN.hpp

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS)  $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all