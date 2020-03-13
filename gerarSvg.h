#ifndef _GERARSVG_H_
#define _GERARSVG_H_

#include <stdio.h>

void svg_adicionarTagInicial(FILE* arquivoSaida);

void svg_adicionarTagFinal(FILE* arquivoSaida);

void svg_imprimirVetorFormas(FILE* arquivoSaida, int tamanho);

void svg_imprimirVetorTextos(FILE* arquivoSaida, int tamanho);

#endif
