OFILES = main.o \
		affichages.o \
		plateau.o \
		serpent.o \
		pomme.c \
		menu.o \
		gameover.o

menu : menu.c snake.h
	gcc -Wall -ansi -o menu.o -c menu.c

gameover : gameover.c snake.h
	gcc -Wall -ansi -o gameover.o -c gameover.c

serpent.o : serpent.c snake.h
	gcc -Wall -ansi -o serpent.o -c serpent.c

pomme.o : pomme.c snake.h
	gcc -Wall -ansi -o pomme.o -c pomme.c

affichages.o : affichages.c snake.h
	gcc -Wall -ansi -o affichages.o -c affichages.c 

plateau.o : plateau.c snake.h
	gcc -Wall -ansi -o plateau.o -c plateau.c

main.o : main.c snake.h
	gcc -Wall -ansi -o main.o -c main.c

snake : ${OFILES}
	gcc -Wall -ansi -o snake ${OFILES} -lgraph
	
run : snake
	./snake