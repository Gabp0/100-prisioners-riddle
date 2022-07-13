# CC = gcc
# CFLAGS = -lstdc++
# objects = main.o Riddle.o

# # defaut
# all: 100-prisioners-riddle 

# # ligacao
# 100-prisioners-riddle: $(objects)
# 	gcc -o 100-prisioners-riddle $(objects)

# # compilacao
# main.o: main.cpp Riddle.h
# Riddle.o: Riddle.cpp Riddle.h

all: 
	gcc main.cpp Riddle.cpp -lstdc++ -o 100-prisioners-riddle