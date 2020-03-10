#include "processarEntrada.h"

#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#include "objetos/forma.h"
#include "objetos/texto.h"

void processarEntradaGeo() {
    char operacao[8], corBorda[32], corPreenchimento[32];
    int id;
	double x, y, r, w, h;

    FILE* arquivoEntradaGeo = getArquivoEntradaGeo();

	Forma* vetorFormas = getVetorFormas();

	while(1) {
		fscanf(arquivoEntradaGeo, "%s", operacao);

		if(feof(arquivoEntradaGeo)) {
			break;
		}

		if(!strcmp(operacao, "c")) {
			fscanf(arquivoEntradaGeo, "%d %lf %lf %lf %s %s", &id, &r, &x, &y, corBorda, 
			corPreenchimento);

			Forma forma = criarForma(id, x, y, r, 0, 0, corBorda, corPreenchimento, "c");

			vetorFormas[id] = forma;
		}

		if(!strcmp(operacao, "r")) {
			fscanf(arquivoEntradaGeo, "%d %lf %lf %lf %lf %s %s", &id, &w, &h, &x, &y, corBorda, 
			corPreenchimento);

			Forma forma = criarForma(id, x, y, 0, w, h, corBorda, corPreenchimento, "r");

			vetorFormas[id] = forma;
		}
	}
}