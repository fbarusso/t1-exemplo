#ifndef _FORMA_H_
#define _FORMA_H_

typedef void* Forma;

Forma criarForma(int id, double x, double y, double r, double w, double h, char* corBorda, 
char* corPreenchimento);

int getShapeId(Forma formaParametro);

Forma* getVetorFormas();

void alocarVetorFormas(int tamanho);

void freeVetorFormas(Forma* vetor, int tamanho);

#endif
