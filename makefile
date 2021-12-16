mainmake: main.c read.c read.h client.c client.h account.c account.h
	gcc -o main main.c read.c client.c account.c
