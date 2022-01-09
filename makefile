mainmake: main.c read.c read.h client.c client.h bank.c bank.h date.c date.h
	gcc -g -o   main main.c read.c client.c bank.c date.c
