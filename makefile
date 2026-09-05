
run: build/snake_game
	./build/snake_game

build/snake_game: build/game.o build/board.o build/snake.o build/node.o build/position.o
	gcc build/game.o build/board.o build/snake.o build/node.o build/position.o -o build/snake_game

build/game.o: src/game.c
	gcc -Iinclude -g -c src/game.c -o build/game.o

build/board.o: src/board.c
	gcc -Iinclude -g -c src/board.c -o build/board.o

build/snake.o: src/snake.c
	gcc -Iinclude -g -c src/snake.c -o build/snake.o

build/node.o: src/node.c
	gcc -Iinclude -g -c src/node.c -o build/node.o

build/position.o: src/position.c
	gcc -Iinclude -g -c src/position.c -o build/position.o

run_tests: run_test_position run_test_node

run_test_board: test_board
	./test_board

run_test_snake: test_snake
	./test_snake

run_test_node: test_node
	./test_node

run_test_position: test_position
	./test_position

test_board: tests/test_board.c src/board.c src/snake.c src/node.c src/position.c
	gcc -Iinclude tests/test_board.c src/board.c src/snake.c src/node.c src/position.c -o test_board

test_snake: tests/test_snake.c src/snake.c src/board.c src/node.c src/position.c
	gcc -Iinclude tests/test_snake.c src/snake.c src/board.c src/node.c src/position.c -o test_snake

test_node: tests/test_node.c src/node.c src/position.c
	gcc -Iinclude tests/test_node.c src/node.c src/position.c -o test_node

test_position: tests/test_position.c  src/position.c
	gcc -Iinclude tests/test_position.c src/position.c -o test_position
