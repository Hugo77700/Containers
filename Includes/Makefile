# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:59:43 by hcherpre          #+#    #+#              #
#    Updated: 2023/01/11 17:53:06 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Containers

SRCS =	main.cpp\

CC = c++

OBJS_PATH = objects/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.cpp=.o}}

CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g3

$(NAME_FT): $(OBJS_FT)
	$(CXX) $(CXXFLAGS) -o $(NAME_FT) $(OBJS_FT) 

$(NAME_STD): $(OBJS_STD)
	$(CXX) $(CXXFLAGS) -o $(NAME_STD) $(OBJS_STD) 


${OBJS_PATH}%.o: ${SRCS_PATH}%.cpp
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all:        $(NAME)

$(NAME):    $(OBJS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re