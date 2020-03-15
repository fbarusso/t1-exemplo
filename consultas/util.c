#include "util.h"

#include <stdio.h>
#include <math.h>

double util_distanciaEuclidiana(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
}

double util_clamp(double valor, double minimo, double maximo) {
	if(valor > maximo) {
		return maximo;
	}
	else if(valor < minimo) {
		return minimo;
	}
	return valor;
}

double util_menorValor(double valor1, double valor2) {
	if(valor1 < valor2) {
		return valor1;
	}
	return valor2;
}

double util_maiorValor(double valor1, double valor2) {
	if(valor1 > valor2) {
		return valor1;
	}
	return valor2;
}