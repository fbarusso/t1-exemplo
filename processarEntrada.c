#include "processarEntrada.h"

#include <stdio.h>
#include<string.h>
#include "arquivos.h"
#include "objetos/forma.h"

void processarEntrada() {
    char operacao[8], corBorda[32], corPreenchimento[32];
    int nx, id;
	double x, y, r, w, h;

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

	Forma* vetorFormas = getVetorFormas();

    while(1) {
        fscanf(arquivoEntradaGeo, "%s", operacao);

        if(feof(arquivoEntradaGeo)) {
            break;
        }

		if(!strcmp(operacao, "c")) {
			fscanf(arquivoEntradaGeo, "%d %lf %lf %lf %s %s", &id, &r, &x, &y, corBorda, 
			corPreenchimento);

			Forma forma = criarForma(id, x, y, r, 0, 0, corBorda, corPreenchimento);

			vetorFormas[id] = forma;
		}
	}

	freeVetorFormas(vetorFormas, nx);

}