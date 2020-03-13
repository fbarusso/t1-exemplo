#include "gerarSvg.h"

#include <string.h>
#include "objetos/forma.h"
#include "objetos/texto.h"

void svg_adicionarTagInicial(FILE* arquivoSaida) {
	fprintf(arquivoSaida, "<svg>\n");
}

void svg_adicionarTagFinal(FILE* arquivoSaida) {
	fprintf(arquivoSaida, "\n</svg>");
}

void svg_imprimirForma(FILE* arquivoSaida, Forma forma) {
	if(!strcmp(forma_getTipo(forma), "c")) {
		fprintf(arquivoSaida, "\n\t<circle\n\t\tid=\"%d\"", forma_getId(forma));
		fprintf(arquivoSaida, "\n\t\tcx=\"%lf\"", forma_getX(forma));
		fprintf(arquivoSaida, "\n\t\tcy=\"%lf\"", forma_getY(forma));
		fprintf(arquivoSaida, "\n\t\tr=\"%lf\"", forma_getR(forma));
		fprintf(arquivoSaida, "\n\t\tstroke=\"%s\"", forma_getCorBorda(forma));
		fprintf(arquivoSaida, "\n\t\tfill=\"%s\"\n\t/>\n", forma_getCorPreenchimento(forma));
	}

	else {
		fprintf(arquivoSaida, "\n\t<rect\n\t\tid=\"%d\"", forma_getId(forma));
		fprintf(arquivoSaida, "\n\t\tx=\"%lf\"", forma_getX(forma));
		fprintf(arquivoSaida, "\n\t\ty=\"%lf\"", forma_getY(forma));
		fprintf(arquivoSaida, "\n\t\twidth=\"%lf\"", forma_getW(forma));
		fprintf(arquivoSaida, "\n\t\theight=\"%lf\"", forma_getH(forma));
		fprintf(arquivoSaida, "\n\t\tstroke=\"%s\"", forma_getCorBorda(forma));
		fprintf(arquivoSaida, "\n\t\tfill=\"%s\"\n\t/>\n", forma_getCorPreenchimento(forma));
	}
}

void svg_imprimirVetorFormas(FILE* arquivoSaida, int tamanho) {
	Forma* vetorFormas = forma_getVetor();
	for(int i = 0; i < tamanho; i++) {
		if(vetorFormas[i] != NULL) {
			svg_imprimirForma(arquivoSaida, vetorFormas[i]);
		}
	}
}

void svg_imprimirTexto(FILE* arquivoSaida, Forma texto) {
	fprintf(arquivoSaida, "\n\t<text id=\"%d\"", texto_getId(texto));
	fprintf(arquivoSaida, " x=\"%lf\"", texto_getX(texto));
	fprintf(arquivoSaida, " y=\"%lf\"", texto_getY(texto));
	fprintf(arquivoSaida, " stroke=\"%s\"", texto_getCorBorda(texto));
	fprintf(arquivoSaida, " fill=\"%s\">", texto_getCorPreenchimento(texto));
	fprintf(arquivoSaida, " %s", texto_getConteudo(texto));
	fprintf(arquivoSaida, " </text>\n");
}

void svg_imprimirVetorTextos(FILE* arquivoSaida, int tamanho) {
	Texto* vetorTextos = texto_getVetor();
	for(int i = 0; i < tamanho; i++) {
		if(vetorTextos[i] != NULL) {
			svg_imprimirTexto(arquivoSaida, vetorTextos[i]);
		}
	}
}