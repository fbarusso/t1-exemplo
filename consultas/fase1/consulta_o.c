#include "fase1.h"

#include <stdio.h>
#include <string.h>
#include "stdbool.h"
#include "../../objetos/forma.h"
#include "../util.h"
#include "../../arquivos.h"
#include "../../gerarSvg.h"

bool circulo_cirulo(Forma circulo1, Forma circulo2) {
	return util_distanciaEuclidiana(forma_getX(circulo1), forma_getY(circulo1), forma_getX(circulo2), 
	forma_getY(circulo2)) < forma_getR(circulo1) + forma_getR(circulo2);
}

bool retangulo_retangulo(Forma retangulo1, Forma retangulo2) {
	return (forma_getX(retangulo1) < forma_getXMaximo(retangulo2)) 
	&& (forma_getXMaximo(retangulo1) > forma_getX(retangulo2)) 
	&& (forma_getY(retangulo1) < forma_getYMaximo(retangulo2)) 
	&& (forma_getYMaximo(retangulo1) > forma_getY(retangulo2));
}

bool circulo_retangulo(Forma circulo, Forma retangulo) {
	double xMaisProximo = util_clamp(forma_getX(circulo), forma_getX(retangulo), 
	forma_getXMaximo(retangulo));
	double yMaisProximo = util_clamp(forma_getY(circulo), forma_getY(retangulo), 
	forma_getYMaximo(retangulo));

	return(util_distanciaEuclidiana(forma_getX(circulo), forma_getY(circulo), 
	xMaisProximo, yMaisProximo) < forma_getR(circulo));
}

void consulta_o(int j, int k) {
	Forma forma1 = forma_getFormaPorId(j);
	Forma forma2 = forma_getFormaPorId(k);

	bool sobrepoe = false;
	double x1, y1, x2, y2, w, h;

	FILE* arquivoSaidaConsultaTxt = getArquivoSaidaConsultaTxt();
	FILE* arquivoSaidaConsultaSvg = getArquivoSaidaConsultaSvg();

	if(!strcmp(forma_getTipo(forma1), forma_getTipo(forma2))) {
		if(!strcmp(forma_getTipo(forma1), "c")) {
			sobrepoe = circulo_cirulo(forma1, forma2);
		}
		else {
			sobrepoe = retangulo_retangulo(forma1, forma2);
		}
	}

	else {
		if(!strcmp(forma_getTipo(forma1), "c")) {
			sobrepoe = circulo_retangulo(forma1, forma2);
		}

		else {
			sobrepoe = circulo_retangulo(forma2, forma1);
		}
	}

	x1 = util_menorValor(forma_getXMinimo(forma1), forma_getXMinimo(forma2));
	y1 = util_menorValor(forma_getYMinimo(forma1), forma_getYMinimo(forma2));
	x2 = util_maiorValor(forma_getXMaximo(forma1), forma_getXMaximo(forma2));
	y2 = util_maiorValor(forma_getYMaximo(forma1), forma_getYMaximo(forma2));
	w = x2 - x1;
	h = y2 - y1;

	if(sobrepoe) {
		fprintf(arquivoSaidaConsultaTxt, "o? %d %d \nSIM\n\n", j, k);
		svg_imprimirRetanguloDelimitador(arquivoSaidaConsultaSvg, x1, y1, w, h, true);
	}

	else {
		fprintf(arquivoSaidaConsultaTxt, "o? %d %d \nNAO\n\n", j, k);
		svg_imprimirRetanguloDelimitador(arquivoSaidaConsultaSvg, x1, y1, w, h, false);
	}
}