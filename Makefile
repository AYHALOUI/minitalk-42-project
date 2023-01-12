# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 12:27:57 by ahaloui           #+#    #+#              #
#    Updated: 2023/01/12 11:36:45 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Files Mandatory
EXEC_CLT = client
EXEC_SRV = server

# Executable Files Bonus
EXEC_SRV_B = server_bonus
EXEC_CLT_B = client_bonus

# Source Files Mandatory
UTILS = minitalk_utils.c
SRC_SRV = server.c
SRC_CLT = client.c

# Source Files Bonus
SRC_SRV_B = server_bonus.c
SRC_CLT_B = client_bonus.c

#OBJ_UTILS = minitalk_utils.o
OBJ_UTILS = $(UTILS:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra

%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@
	
# Rule of Mandatory part
all: $(EXEC_SRV) $(EXEC_CLT) minitalk.h

$(EXEC_SRV) : $(OBJ_UTILS) $(SRC_SRV)
	@$(CC) $(FLAGS) $(SRC_SRV) $(OBJ_UTILS) -o $(EXEC_SRV)
$(EXEC_CLT) : $(OBJ_UTILS) $(SRC_CLT)
	@$(CC) $(FLAGS) $(SRC_CLT) $(OBJ_UTILS) -o $(EXEC_CLT)

# Rule of Bonus part
bonus : $(EXEC_SRV_B) $(EXEC_CLT_B) minitalk.h

$(EXEC_SRV_B) : $(OBJ_UTILS) $(SRC_SRV_B)
	@$(CC) $(FLAGS) $(SRC_SRV_B) $(OBJ_UTILS) -o $(EXEC_SRV_B)
$(EXEC_CLT_B) : $(OBJ_UTILS) $(SRC_CLT_B)
	@$(CC) $(FLAGS) $(SRC_CLT_B) $(OBJ_UTILS) -o $(EXEC_CLT_B)

clean:
	@rm -f $(OBJ_UTILS)	

fclean: clean
	@rm -f $(EXEC_SRV) $(EXEC_CLT) $(EXEC_CLT_B) $(EXEC_SRV_B)

re: fclean all 

re_bonus: fclean bonus