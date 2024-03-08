FLAGS = -Wall -Wextra -Werror -D
BUFF1 = 400
BUFF2 = 1
BUFF3 = 9000

make tests: tests_joke1 tests_joke2 tests_empty tests_stdin1 tests_stdin2

make tests_joke1:
  @cc $(FLAGS) BUFFER_SIZE=$(BUFF1) -o tests.out .test/.tests_joke.c ../get_next_line.c ../get_next_line_utils.c -I ../
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out | sed 's/$/\$/'
  @rm tests.out

make tests_joke2:
  @cc $(FLAGS) BUFFER_SIZE=$(BUFF2) -o tests.out .test/.tests_joke.c ../get_next_line.c ../get_next_line_utils.c -I ../
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out | sed 's/$/\$/'
  @rm tests.out

make tests_empty
  @cc $(FLAGS) BUFFER_SIZE=$(BUFF3) -o tests.out .test/.tests_empty.c ../get_next_line.c ../get_next_line_utils.c -I ../
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out | sed 's/$/\$/'
  @rm tests.out

make tests_stdin1
  @cc $(FLAGS) BUFFER_SIZE=$(BUFF3) -o tests.out .test/.tests_stdin.c ../get_next_line.c ../get_next_line_utils.c -I ../
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out < poem.txt | sed 's/$/\$/'
  @rm tests.out

make tests_stdin2
  @cc $(FLAGS) BUFFER_SIZE=$(BUFF2) -o tests.out .test/.tests_stdin.c ../get_next_line.c ../get_next_line_utils.c -I ../
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out | sed 's/$/\$/'
  @rm tests.out
