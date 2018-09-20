# ft_select

## About ft_select

* ft_select is a project to learn how use the [termcaps](https://en.wikipedia.org/wiki/Termcap), and how manage signals.

* In this project, i created a user interface, where the user can go to left, right, select, delete and write, in the terminal, arguments that were passed to ft_select.

## What do you need to compile ft_select ?

* gcc or clang

* make

* C library

* ar

* [libncurses5](https://en.wikipedia.org/wiki/Ncurses)

## How to compile ft_select ?

* Use `make` to compile `ft_select`.

## Usage:

* `./ft_select [arguments...]`. after that, ft_select clears the terminal and writes the arguments. You can go to left with "<=", right "=>", select "space", and "enter" to write selected arguments in the terminal, and delete the arguments where the cursor is with del.

* the selected arguments are in reverse video.

* the cursor is on the argument that is underlined.

## Rules of Makefile:

all: compile `libft.a`, `ft_select`

clean: delete objects

fclean: call clean and delete `libft.a`, `ft_select`

re: call fclean and all
