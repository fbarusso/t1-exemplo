#ifndef _UTIL_H_
#define _UTIL_H_

// Retorna a distancia euclidiana entre dois pontos x1y1, x2y2.
double util_distanciaEuclidiana(double x1, double y1, double x2, double y2);

// Retorna o valor mas proximo entre minimo/maximo.
double util_clamp(double valor, double minimo, double maximo);

// Retorna o menor entre dois valores.
double util_menorValor(double valor1, double valor2);

// Retorna o maior entre dois valores.
double util_maiorValor(double valor1, double valor2);

#endif
