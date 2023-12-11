all:
	gcc -c -g src/app.c -o lib/app.o 
	gcc lib/app.o main.c -o a.exe -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_test -lgdi32 -luser32