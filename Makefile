#CFLAGS = -Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
CFLAGS = -Wall -Wextra -std=c89 -pedantic

all: hello.exe

hello.exe: hello.o
	gcc -o $@ $< $(CFLAGS)
  
hello.o: hello.c
	gcc -c $< $(CFLAGS)
  
clean:
	rm hello.o hello.exe