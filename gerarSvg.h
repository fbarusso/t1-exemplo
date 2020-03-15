#ifndef _GERARSVG_H_
#define _GERARSVG_H_

#include <stdio.h>
#include <stdbool.h>

void svg_adicionarTagInicial(FILE* arquivoSaida);

void svg_adicionarTagFinal(FILE* arquivoSaida);

void svg_imprimirVetorFormas(FILE* arquivoSaida, int tamanho);

void svg_imprimirVetorTextos(FILE* arquivoSaida, int tamanho);

void svg_imprimirRetanguloDelimitador(FILE* arquivoSaida, double x1, double y1, double w, double h, 
bool sobrepoe);

#endif
