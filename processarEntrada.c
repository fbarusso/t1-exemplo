#include "processarEntrada.h"

#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#include "objetos/forma.h"
#include "objetos/texto.h"
#include "processarEntradaGeo.h"

void processarEntrada() {
	char operacao[8];
	int nx;

	FILE* arquivoEntradaGeo = getArquivoEntradaGeo();

	fscanf(arquivoEntradaGeo, "%s", operacao);

	if(!strcmp(operacao, "nx")) {
		fscanf(arquivoEntradaGeo, "%d", &nx);
	}

	else {
		nx = 1000;
		rewind(arquivoEntradaGeo);
	}

	alocarVetorFormas(nx);
	alocarVetorTextos(nx);

	inicializarVetorFormas(nx);
	inicializarVetorTextos(nx);

	processarEntradaGeo();

	freeVetorFormas(nx);
	freeVetorTextos(nx);
}