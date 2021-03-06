CC = gcc
COMPILER_FLAGS = -std=c99 -fstack-protector-all
LINKER_FLAGS = -lm
EXEC_NAME = siguel
OBJECTS = main.o argumentos.o arquivos.o processarEntrada.o processarEntradaGeo.o gerarSvg.o processarEntradaQry.o consultas/util.o consultas/fase1/consulta_o.o objetos/forma.o objetos/texto.o

all: $(EXEC_NAME)

siguel: $(OBJECTS)
	$(CC) $(OBJECTS) -g $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

clean:
	rm -rf *.o siguel objetos/*.o saida/*