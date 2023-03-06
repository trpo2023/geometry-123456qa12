all: helloworld.c
	gcc helloworld.c -Wall -Werror 
geometry: geometry.c
	gcc geometry.c -Wall -Werror -lm -o geometry
	