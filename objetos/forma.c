#include "forma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structForma {
	int id;
	double x, y, r, w, h;
	char corBorda[32], corPreenchimento[32], tipo[4];
};

typedef struct structForma * ponteiroForma;

static Forma* vetorFormas;

static int contador = -1;

Forma forma_criar(int id, double x, double y, double r, double w, double h, char* corBorda, 
char* corPreenchimento, char* tipo) {

	ponteiroForma forma;

	forma = malloc(sizeof(struct structForma));

	forma->id = id;
	forma->x = x;
	forma->y = y;
	forma->r = r;
	forma->w = w;
	forma->h = h;

	strcpy(forma->corBorda, corBorda);
	strcpy(forma->corPreenchimento, corPreenchimento);
	strcpy(forma->tipo, tipo);

	return forma;
}

int forma_getContador() {
	contador++;
	return contador;
}

int forma_getId(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->id;
}

double forma_getX(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->x;
}

double forma_getY(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->y;
}

double forma_getR(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->r;
}

double forma_getW(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->w;
}

double forma_getH(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->h;
}

char* forma_getCorBorda(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->corBorda;
}

char* forma_getCorPreenchimento(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->corPreenchimento;
}

char* forma_getTipo(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->tipo;
}

// TODO: Arrumar para ser acessado fora
void forma_free(Forma formaParametro) {
	free(formaParametro);
}

Forma* forma_getVetor() {
	return vetorFormas;
}

void forma_alocarVetor(int tamanho) {
	vetorFormas = forma_getVetor();
	vetorFormas = malloc(tamanho * sizeof(struct structForma));
}

void forma_inicializarVetor(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		vetorFormas[i] = NULL;
	}
}

void forma_freeVetor(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		if(vetorFormas[i] != NULL) {
			forma_free(vetorFormas[i]);
		}
	}
	free(vetorFormas);
}