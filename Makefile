FLAGS = -Wall -Wextra -Werror
BUFF1 = 5
BUFF2 = 1
BUFF3 = 1025
BUFF4 = 0

tests: tests_42 tests_empty_file tests_stdin1 tests_stdin2 tests_buffer0

tests_42:
	@cc $(FLAGS) -D BUFFER_SIZE=$(BUFF1) -o tests.out tests/42.c ../get_next_line.c ../get_next_line_utils.c -I ../
	@valgrind --leak-check=full --show-leak-kinds=all ./tests.out
	@rm tests.out

tests_empty_file:
	@cc $(FLAGS) -D BUFFER_SIZE=$(BUFF2) -o tests.out tests/empty_file.c ../get_next_line.c ../get_next_line_utils.c -I ../
	@valgrind --leak-check=full --show-leak-kinds=all ./tests.out
	@rm tests.out

tests_stdin1:
	@cc $(FLAGS) -D BUFFER_SIZE=$(BUFF3) -o tests.out tests/stdin.c ../get_next_line.c ../get_next_line_utils.c -I ../
	@valgrind --leak-check=full --show-leak-kinds=all ./tests.out < text_files/stdin_long.txt
	@rm tests.out

tests_stdin2:
	@cc $(FLAGS) -o tests.out tests/stdin.c ../get_next_line.c ../get_next_line_utils.c -I ../
	@valgrind --leak-check=full --show-leak-kinds=all ./tests.out < text_files/stdin_long.txt
	@rm tests.out

tests_buffer0:
	@cc $(FLAGS) -D BUFFER_SIZE=$(BUFF4) -o tests.out tests/endlonly.c ../get_next_line.c ../get_next_line_utils.c -I ../
	@valgrind --leak-check=full --show-leak-kinds=all ./tests.out < text_files/endlonly.txt
	@rm tests.out
