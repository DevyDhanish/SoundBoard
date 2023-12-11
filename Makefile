all:
	gcc -c -g -Iinclude/ src/color.c -o lib/color.o
	gcc -c -g -Iinclude/ src/app.c -o lib/app.o 
	ar rcs lib/libsb.a lib/*.o
	gcc main.c -o a.exe -Iinclude -Llib -lsb -lmingw32 -lSDL2main -lSDL2 -lSDL2_test -lgdi32 -luser32