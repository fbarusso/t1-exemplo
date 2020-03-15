#ifndef _FORMA_H_
#define _FORMA_H_

typedef void* Forma;

Forma forma_criar(int id, double x, double y, double r, double w, double h, char* corBorda, 
char* corPreenchimento, char* tipo);

int forma_getContador();

int forma_getId(Forma formaParametro);

double forma_getX(Forma formaParametro);

double forma_getY(Forma formaParametro);

double forma_getR(Forma formaParametro);

double forma_getW(Forma formaParametro);

double forma_getH(Forma formaParametro);

char* forma_getCorBorda(Forma formaParametro);

char* forma_getCorPreenchimento(Forma formaParametro);

char* forma_getTipo(Forma formaParametro);

double forma_getXMaximo(Forma formaParametro);

double forma_getYMaximo(Forma formaParametro);

double forma_getXMinimo(Forma formaParametro);

double forma_getYMinimo(Forma formaParametro);

Forma forma_getFormaPorId(int id);

void forma_free(Forma formaParametro);

Forma* forma_getVetor();

void forma_alocarVetor(int tamanho);

void forma_inicializarVetor(int tamanho);

void forma_freeVetor(int tamanho);

#endif
