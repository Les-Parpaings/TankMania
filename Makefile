##
## MAZE PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Compilation Settings
BIN		:=		TankMania
CC		:=		g++ -g -std=c++17
VALG	:=		valgrind --leak-check=full --log-file=report.txt
SFML	:=		-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window

# Command Settings
rwildcard	=		$(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))
RM			=		@rm --force
FIND		=		@find -name "*.o" -exec printf

# File Settings
DIR		:=		src
EXT		:=		cpp
SRC		:=		$(call rwildcard, $(DIR), *.$(EXT))
OBJ		:=		$(SRC:.$(EXT)=.o)

# Dependencies Settings
LIB		:=		./lib/
INCLUDE	:=		./include/

# Display Settings
RED		:=	\033[1;31m
GREEN	:=	\033[1;32m
YELLOW	:=	\033[1;33m
BLUE	:=	\033[1;34m
CYAN	:=	\033[1;36m
NC		:=	\033[0m
TEXT	:=	$(GREEN)➜$(NC)  $(CYAN)Root$(NC)
INTRO	:=	$(YELLOW)================================================================$(NC)\n

.PHONY: all clean fclean re compil valgrind

all:	$(BIN)

#Compiled all .c file not compiled in .o
$(OBJ):	%.o: %.$(EXT)
		@$(CC) -I$(INCLUDE) -c -o $@ $<
		@printf "$(TEXT)$(BLUE) file $(RED)./$@$(BLUE) created$(NC)\n"

#Compiled project with lib and all .o files
$(BIN):	$(OBJ)
		@$(CC) -o $@ $^ -I$(INCLUDE) $(SFML)
		@printf "\n$(INTRO)$(YELLOW) · Compilation Succesfully Finished$(NC)\n$(INTRO)\n"

#Removes all .o files
clean:
#		$(call INTRO_DISPLAY, ${INTRO_CLEAN})
		@$(FIND) "$(TEXT)$(BLUE) file $(RED){}$(BLUE) removed$(NC)\n" \;
		@$(RM) $(OBJ)

#Removes all useless files, binary and library
fclean:	clean
#		$(call INTRO_DISPLAY, ${INTRO_FCLEAN})
		@find -name "prgm" -exec printf "$(TEXT)$(BLUE) binary $(RED)$(BIN)$(BLUE) removed$(NC)\n" \;
		@$(RM) $(BIN)
		@$(RM) report.txt
		@find -name "vgcore.*" -delete
		@find -name "report.txt.core.*" -delete

#Clean all and compile the project
re:	fclean all

#Recompile and Start the project
compil:	re
	@./$(BIN)

#Start the project with valgrind in a report file
valgrind:
	@$(VALG) ./$(BIN)
