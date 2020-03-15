#include "processarEntrada.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arquivos.h"
#include "argumentos.h"
#include "objetos/forma.h"
#include "objetos/texto.h"
#include "processarEntradaGeo.h"
#include "processarEntradaQry.h"
#include "gerarSvg.h"

void processarEntrada() {
	char operacao[8];
	int nx;

	FILE* arquivoEntradaGeo = getArquivoEntradaGeo();
	FILE* arquivoSaidaSvg =  getArquivoSaidaSvg();
	FILE* arquivoSaidaConsultaSvg = getArquivoSaidaConsultaSvg();

	fscanf(arquivoEntradaGeo, "%s", operacao);

	if(!strcmp(operacao, "nx")) {
		fscanf(arquivoEntradaGeo, "%d", &nx);
	}

	else {
		nx = 1000;
		rewind(arquivoEntradaGeo);
	}

	forma_alocarVetor(nx);
	texto_alocarVetor(nx);

	forma_inicializarVetor(nx);
	texto_inicializarVetor(nx);

	processarEntradaGeo();

	svg_adicionarTagInicial(arquivoSaidaSvg);
	svg_imprimirVetorFormas(arquivoSaidaSvg, nx);
	svg_imprimirVetorTextos(arquivoSaidaSvg, nx);
	svg_adicionarTagFinal(arquivoSaidaSvg);

	if(getFlagConsulta()) {
		svg_adicionarTagInicial(arquivoSaidaConsultaSvg);
		processarEntradaQry();
		svg_imprimirVetorFormas(arquivoSaidaConsultaSvg, nx);
		svg_imprimirVetorTextos(arquivoSaidaConsultaSvg, nx);
		svg_adicionarTagFinal(arquivoSaidaConsultaSvg);
	}

	forma_freeVetor(nx);
	texto_freeVetor(nx);
}