##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

BINARY	=	tankmania
CC		=	g++ -g
VALG	=	valgrind --leak-check=full --log-file=report.txt
CSFML	=	-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window \
			-lsfml-network

DIR		=	src/class \
			src/game \
			src/init \
			src/lobby \
			src/menu_main \
			src/setup \
			src/utils \

SRC		=	$(wildcard *.cpp $(foreach fd, $(DIR), $(fd)/*.cpp))
OBJ		=	$(SRC:.cpp=.o)

HEAD	=	./include/

RED		=	\033[1;31m
GREEN	=	\033[1;32m
BLUE	=	\033[1;34m
CYAN	=	\033[1;36m
NC		=	\033[0m

TEXT	=	$(GREEN)➜$(NC)  $(CYAN)Root$(NC)
FIND	=	@find -name "*.o" -exec printf

RM		=	rm --force

.PHONY: all clean fclean re

all:	$(BINARY)

# Compiled all .cpp file not compiled in .o
$(OBJ): %.o: %.cpp
		@$(CC) -I$(HEAD) -c -o $@ $<
		@printf "$(TEXT)$(BLUE) file $(RED)$@$(BLUE) created$(NC)\n"

# Compiled project with lib and all .o files
$(BINARY):	$(OBJ)
		@$(CC) -o $@ $^ -I$(HEAD) $(CSFML)
		@printf "$(TEXT)$(BLUE) Compilation done$(NC)\n"

# Removes all .o files
clean:
		@$(FIND) "$(TEXT)$(BLUE) file $(RED){}$(BLUE) removed$(NC)\n" \;
		@$(RM) $(OBJ)

# Removes all useless files, binary and library
fclean:	clean
		@printf "$(TEXT)$(BLUE) binary $(RED)$(BINARY)$(BLUE) removed$(NC)\n"
		@$(RM) $(BINARY)
		@printf "$(TEXT)$(BLUE) valgrind reports removed$(NC)\n"
		@find -name "vgcore.*" -delete
		@$(RM) report.txt
		@find -name "report.txt.core.*" -delete

# Clean all and compile the project
re:
		@$(MAKE) fclean -j --no-print
		@$(MAKE) -j --no-print

# Start the project
compil:	re
		@./$(BINARY)

# Start the project with valgrind in a report file
valgrind:
		@$(VALG) ./$(BINARY)
