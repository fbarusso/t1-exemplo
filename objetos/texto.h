#ifndef _TEXTO_H_
#define _TEXTO_H_

typedef void* Texto;

Texto criarTexto(int id, double x, double y, char* conteudo, char* corBorda, char* corPreenchimento);

void freeTexto(Texto textoParametro);

Texto* getVetorTextos();

void alocarVetorTextos(int tamanho);

void inicializarVetorTextos(int tamanho);

void freeVetorTextos(int tamanho);

#endif
