compiler=g++
objects=main.o lista.o pilha.o
gen_object=$(compiler) -c

all: program

program: $(objects)
	$(compiler) $(objects) -o main.exe

main.o: main.c
	$(gen_object) main.c

lista.o: lista.c
	$(gen_object) lista.c

pilha.o: pilha.c
	$(gen_object) pilha.c

clean:
	del *.o *.exe *.asm

asm: $(objects)
	$(compiler) -S $(objects)
