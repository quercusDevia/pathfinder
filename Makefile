FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: pathfinder

pathfinder: objFiles
	@make -C ./libmx/
	@clang $(FLAGS) obj/*.o -Ilibmx/inc -Iinc libmx/libmx.a -o pathfinder

objFiles: src/*.c
	@mkdir -p obj
	@clang $(FLAGS) -c src/*.c -Ilibmx/inc -Iinc
	@mv *.o obj/

clean:
	@rm -rf obj

uninstall:
	@rm -rf pathfinder
	@rm -rf obj
	@make uninstall -C ./libmx/

reinstall: uninstall pathfinder
