#include "processarEntradaQry.h"

#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#include "consultas/fase1/fase1.h"

void processarEntradaQry() {
	char operacao[8];
	int j, k;

	FILE* arquivoEntradaQry = getArquivoEntradaQry();

	while(1) {
		fscanf(arquivoEntradaQry, "%s", operacao);

		if(feof(arquivoEntradaQry)) {
			break;
		}

		if(!strcmp(operacao, "o?")) {
			fscanf(arquivoEntradaQry, "%d %d", &j, &k);
			consulta_o(j, k);
		}

		/*
		else if(!strcmp(operacao, "i?")) {

		}

		else if(!strcmp(operacao, "pnt")) {

		}

		else if(!strcmp(operacao, "pnt*")) {

		}

		else if(!strcmp(operacao, "delf")) {

		}

		else if(!strcmp(operacao, "felf*")) {

		}
		*/
	}
}