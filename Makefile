CC=g++ -g
game:main.o module.o
        ${CC} -o game main.o module.o
main.o:main.cpp
        ${CC} -c main.cpp
module.o:module.cpp module.h
        ${CC} -c module.cpp
