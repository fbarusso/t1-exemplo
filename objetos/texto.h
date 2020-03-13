#ifndef _TEXTO_H_
#define _TEXTO_H_

typedef void* Texto;

Texto texto_criar(int id, double x, double y, char* conteudo, char* corBorda, char* corPreenchimento);

int texto_getId(Texto parametroTexto);

double texto_getX(Texto parametroTexto);

double texto_getY(Texto parametroTexto);

char* texto_getConteudo(Texto parametroTexto);

char* texto_getCorBorda(Texto parametroTexto);

char* texto_getCorPreenchimento(Texto parametroTexto);

void texto_free(Texto textoParametro);

Texto* texto_getVetor();

void texto_alocarVetor(int tamanho);

void texto_inicializarVetor(int tamanho);

void texto_freeVetor(int tamanho);

#endif