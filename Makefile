#CFLAGS = -Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
CFLAGS = -Wall -Wextra -std=c89 -pedantic

all: poj.exe

poj.exe: main.o
	gcc -o $@ $< $(CFLAGS)
  
main.o: main.c
	gcc -c $< $(CFLAGS)
  
clean:
	rm main.o poj.exe