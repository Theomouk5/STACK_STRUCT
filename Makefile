run: src/main.c src/stack.c
	gcc -Iinclude src/*.c -o build/prog
	./build/prog
