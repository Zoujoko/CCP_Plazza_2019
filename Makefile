##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

RECEPTION_DIR	=	./src/Reception/


SRC	=	src/main.cpp					\
		src/Error.cpp 					\
		src/Pizza.cpp 					\
		src/SharedMemory.cpp 			\
		src/Kitchen.cpp 				\
		src/Cook.cpp 					\
		src/Mutex.cpp 					\
		src/Process.cpp					\
		$(RECEPTION_DIR)Prompt.cpp 		\
		$(RECEPTION_DIR)Reception.cpp	\

SRC_TESTS =		src/Error.cpp 					\
				src/Pizza.cpp 					\
				src/SharedMemory.cpp 			\
				src/Kitchen.cpp 				\
				src/Cook.cpp 					\
				src/Mutex.cpp 					\
				src/Process.cpp					\
				$(RECEPTION_DIR)Prompt.cpp 		\
				$(RECEPTION_DIR)Reception.cpp	\
				tests/plazza_tests.cpp 			\

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST =	$(SRC_TESTS:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror -g3 -lpthread -I $(RECEPTION_DIR) --coverage

NAME	=	plazza

all:		build

build:		$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(OBJ)
		@rm -f *~
		@rm -f $(NAME)
		@rm -f vgcore.*
		@rm -f *.gcno
		@rm -f src/*.gcno
		@rm -f src/*.gcda
		@rm -f $(RECEPTION_DIR)*.gcno
		@rm -f $(RECEPTION_DIR)*.gcda
		@rm -f tests/*.gcno
		@rm -f tests/*.gcda
		@rm -f tests/*.o
		@rm -f unit_tests
		@rm -f receptionLog

re:		fclean all

tests_run:    $(OBJ_TEST)
	g++ -o unit_tests $(OBJ_TEST) -lpthread -lcriterion --coverage
	./unit_tests
	@gcovr


.PHONY:		make clean fclean re tests_run
