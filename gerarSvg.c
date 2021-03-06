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
	fprintf(arquivoSaida, "\n\t<text\n\t\tid=\"%d\"", texto_getId(texto));
	fprintf(arquivoSaida, "\n\t\tx=\"%lf\"", texto_getX(texto));
	fprintf(arquivoSaida, "\n\t\ty=\"%lf\"", texto_getY(texto));
	fprintf(arquivoSaida, "\n\t\tstroke=\"%s\"", texto_getCorBorda(texto));
	fprintf(arquivoSaida, "\n\t\tfill=\"%s\">", texto_getCorPreenchimento(texto));
	fprintf(arquivoSaida, "\n\t\t%s", texto_getConteudo(texto));
	fprintf(arquivoSaida, "\n\t</text>\n");
}

void svg_imprimirVetorTextos(FILE* arquivoSaida, int tamanho) {
	Texto* vetorTextos = texto_getVetor();
	for(int i = 0; i < tamanho; i++) {
		if(vetorTextos[i] != NULL) {
			svg_imprimirTexto(arquivoSaida, vetorTextos[i]);
		}
	}
}

void svg_imprimirRetanguloDelimitador(FILE* arquivoSaida, double x1, double y1, double w, double h, 
bool sobrepoe) {
	fprintf(arquivoSaida, "\n\t<rect");
	fprintf(arquivoSaida, "\n\t\tx=\"%lf\"", x1);
	fprintf(arquivoSaida, "\n\t\ty=\"%lf\"", y1);
	fprintf(arquivoSaida, "\n\t\twidth=\"%lf\"", w);
	fprintf(arquivoSaida, "\n\t\theight=\"%lf\"", h);
	fprintf(arquivoSaida, "\n\t\tstroke=\"red\"");
	fprintf(arquivoSaida, "\n\t\tstroke-width=\"2\"");
	if(!sobrepoe) {
		fprintf(arquivoSaida, "\n\t\tstroke-dasharray=\"10\"");
	}
	fprintf(arquivoSaida, "\n\t\tfill=\"none\"\n\t/>\n");
}