FLAGS = -Wall -Wextra -Werror

make tests:
  @cc (FLAGS) -o tests.out .tests.c get_next_line.c get_next_line_utils.c -I ./
  @valgrind --leak-check=full --show-leak-kinds=all ./tests.out
  @rm tests.out
