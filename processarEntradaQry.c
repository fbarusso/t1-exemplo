#include "processarEntradaQry.h"

#include <stdio.h>
#include <string.h>

void processarEntradaQry() {
	char operacao[8];

	FILE* arquivoEntradaQry = getArquivoEntradaQry();

	while(1) {
		fscanf(arquivoEntradaQry, "%s", operacao);

		if(feof(arquivoEntradaQry)) {
			break;
		}

		if(!strcmp(operacao, "o?")) {
			consulta_o();
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

	printf ("Segmentation fault (Core dumped)\n");
}