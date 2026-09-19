# get_next_line tester

This directory contains a small test harness for a `get_next_line`
implementation. The implementation itself is expected to be in the parent
directory:

- `../get_next_line.c`
- `../get_next_line_utils.c`
- `../get_next_line.h`

Run the commands below from this directory (`c_file_reader`). The tests use
relative paths to files in `text_files/`.

## Requirements

- C compiler available as `cc`
- `valgrind`
- a `get_next_line` implementation in the parent directory

## Running the tests

Run the complete test suite:

```sh
make tests
```

Run one test target at a time:

```sh
make tests_42
make tests_empty_file
make tests_stdin1
make tests_stdin2
make tests_buffer0
```

Each target compiles the implementation with a different compile-time
`BUFFER_SIZE`, runs the resulting program under Valgrind, and removes the
temporary `tests.out` executable.

## Tested cases

- `tests_42`: boundary lines around `BUFFER_SIZE=5`, a final line without a
  newline, and `NULL` after EOF
- `tests_empty_file`: reading an empty file with `BUFFER_SIZE=1`
- `tests_stdin1`: a 2100-character line followed by an empty line and EOF,
  with `BUFFER_SIZE=1025` (the test reads standard input redirected from
  `text_files/stdin_long.txt`, containing 2100 `A` characters and two newlines)
- `tests_stdin2`: the same stdin test compiled without passing
  `-D BUFFER_SIZE`, using the default value provided by the implementation
- `tests_buffer0`: three calls with `BUFFER_SIZE=0`, each expected to return
  `NULL` immediately, even though the file contains a newline

## Directory structure

```text
.
├── Makefile
├── README.md
├── tests/
│   ├── 42.c
│   ├── empty_file.c
│   ├── endlonly.c
│   └── stdin.c
└── text_files/
    ├── 42.txt
    ├── empty.txt
    ├── endlonly.txt
    └── stdin_long.txt
```
