mainmake: main.c read.c read.h client.c client.h bank.c bank.h
	gcc -o main main.c read.c client.c bank.c
