#ifndef _FORMA_H_
#define _FORMA_H_

typedef void* Forma;

Forma criarForma(int id, double x, double y, double r, double w, double h, char* corBorda, 
char* corPreenchimento, char* tipo);

int getShapeId(Forma formaParametro);

char* getFormaTipo(Forma formaParametro);

void freeForma(Forma formaParametro);

Forma* getVetorFormas();

void alocarVetorFormas(int tamanho);

void inicializarVetorFormas(int tamanho);

void freeVetorFormas(int tamanho);

#endif
